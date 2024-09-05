#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>
void test01(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&now_time);
}
void test02(){
    auto start = std::chrono::high_resolution_clock::now();

    // 模拟一些工作
    std::this_thread::sleep_for(std::chrono::seconds(3));

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}

void test03(){
     auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

    std::cout << "Milliseconds since epoch: " << millis << "\n";
    std::cout << "Microseconds since epoch: " << micros << "\n";
    std::cout << "Nanoseconds since epoch: " << nanos << "\n";
}
void test04(){
    auto system_start = std::chrono::system_clock::now();
    auto steady_start = std::chrono::steady_clock::now();
    auto highres_start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto system_end = std::chrono::system_clock::now();
    auto steady_end = std::chrono::steady_clock::now();
    auto highres_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> system_elapsed = system_end - system_start;
    std::chrono::duration<double> steady_elapsed = steady_end - steady_start;
    std::chrono::duration<double> highres_elapsed = highres_end - highres_start;

    std::cout << "system_clock elapsed time: " << system_elapsed.count() << " seconds\n";
    std::cout << "steady_clock elapsed time: " << steady_elapsed.count() << " seconds\n";
    std::cout << "high_resolution_clock elapsed time: " << highres_elapsed.count() << " seconds\n";

}
void test05(){
    std::cout << "Waiting for 3 seconds..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Done!" << std::endl;
}
void test06(){
    auto start = std::chrono::system_clock::now();
    auto later = start + std::chrono::minutes(1);

    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::time_t later_time = std::chrono::system_clock::to_time_t(later);

    std::cout << "Start time: " << std::ctime(&start_time);
    std::cout << "Later time (1 minute later): " << std::ctime(&later_time);
}
void test07(){
     std::chrono::minutes mins(3);
    std::chrono::seconds secs = std::chrono::duration_cast<std::chrono::seconds>(mins);

    std::cout << "3 minutes is " << secs.count() << " seconds\n";
}
void test08(){
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::cout << "Current time: " << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << '\n';
}
int main() {

    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    return 0;
}