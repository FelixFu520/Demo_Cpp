#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

class AdvancedTimer {
public:
    // 定时任务结构体
    struct TimerTask {
        std::function<void()> callback; // 回调函数
        std::chrono::milliseconds interval; // 执行间隔
        bool isSingleShot = false; // 是否单次执行
        bool isActive = true; // 任务是否激活
        std::chrono::steady_clock::time_point nextExecutionTime; // 下次执行时间
    };

    // 添加定时任务
    void addTask(std::function<void()> callback, std::chrono::milliseconds interval, bool isSingleShot = false) {
        std::lock_guard<std::mutex> lock(_mutex);
        _tasks.emplace_back(TimerTask{callback, interval, isSingleShot, true, std::chrono::steady_clock::now() + interval});
    }

    // 移除指定的任务
    void removeTask(const std::function<void()>& callback) {
        std::lock_guard<std::mutex> lock(_mutex);
        for (auto it = _tasks.begin(); it != _tasks.end(); ++it) {
            if (it->callback.target_type() == typeid(callback)) {
                it->isActive = false;
                break;
            }
        }
    }

    // 启动定时器线程
    void start() {
        _stopRequested = false;
        _workerThread = std::thread(&AdvancedTimer::_run, this);
    }

    // 停止定时器线程
    void stop() {
        {
            std::lock_guard<std::mutex> lock(_mutex);
            _stopRequested = true;
        }
        _cv.notify_all(); // 唤醒等待的线程
        if (_workerThread.joinable()) {
            _workerThread.join();
        }
    }

private:
    void _run() {
        std::unique_lock<std::mutex> lock(_mutex);
        while (!_stopRequested) {
            // 计算最小的下次执行时间
            auto nextExecution = std::chrono::steady_clock::time_point::max();
            for (const auto& task : _tasks) {
                if (task.isActive) {
                    nextExecution = std::min(nextExecution, task.nextExecutionTime);
                }
            }

            // 等待直到下一个任务应该执行或定时器停止
            if (nextExecution != std::chrono::steady_clock::time_point::max()) {
                _cv.wait_until(lock, nextExecution, [this] { return _stopRequested; });
            }

            // 执行到期的任务
            auto now = std::chrono::steady_clock::now();
            for (auto& task : _tasks) {
                if (!task.isActive || _stopRequested) continue;

                if (task.nextExecutionTime <= now) {
                    // 执行回调
                    task.callback();

                    // 如果是单次任务，标记为非活动状态
                    if (task.isSingleShot) {
                        task.isActive = false;
                    } else {
                        // 更新下次执行时间
                        task.nextExecutionTime += task.interval;
                    }
                }
            }

            // 清理已停止的任务
            _tasks.erase(std::remove_if(_tasks.begin(), _tasks.end(), [](const TimerTask& t) { return !t.isActive; }), _tasks.end());
        }
    }

    std::vector<TimerTask> _tasks; // 任务列表
    std::mutex _mutex; // 互斥锁
    std::condition_variable _cv; // 条件变量
    std::thread _workerThread; // 工作线程
    bool _stopRequested = false; // 是否请求停止
};

int main() {
    AdvancedTimer timer;
    timer.addTask([]() { std::cout << "Periodic task executed" << std::endl; }, std::chrono::seconds(1)); // 每秒执行一次的周期性任务
    timer.addTask([]() { std::cout << "One-time task executed" << std::endl; }, std::chrono::seconds(5), true); // 单次执行的任务

    timer.start(); // 启动定时器
    std::this_thread::sleep_for(std::chrono::seconds(10)); // 让主线程等待一段时间以便观察定时器执行
    timer.stop(); // 停止定时器

    return 0;
}