
#include <iostream>
#include <thread>
#include <chrono>

// 定义定时器回调函数类型
typedef void (*TimerCallback)(void*);

// 定时器类
class SimpleTimer {
public:
    // 构造函数，初始化定时器
    SimpleTimer(TimerCallback callback, void* arg, int durationMs)
        : _callback(callback), _arg(arg), _duration(durationMs) {}

    // 开始计时
    void start() {
        _thread = std::thread([this]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(_duration));
            if (_callback) {
                _callback(_arg);
            }
        });
    }

    // 等待线程结束（如果需要的话）
    void join() {
        if (_thread.joinable()) {
            _thread.join();
        }
    }

private:
    TimerCallback _callback; // 回调函数指针
    void* _arg;            // 回调函数参数
    int _duration;         // 定时器持续时间（毫秒）
    std::thread _thread;   // 线程对象
};

// 示例回调函数
void timerCallback(void* arg) {
    std::cout << "Timer expired!" << std::endl;
}

int main() {
    // 创建并启动定时器，5秒后调用timerCallback
    SimpleTimer t(timerCallback, nullptr, 5000);
    t.start();

    std::cout << "Waiting for timer..." << std::endl;
    t.join(); // 等待定时器任务结束，这一步可选，根据需求决定是否加入

    return 0;
}