#include <iostream>
#include <vector>
#include <list>

// 泛型模板函数
template <typename Container>
void process(const Container& container) {
    std::cout << "Generic container" << std::endl;
}

// 为 std::vector 提供特化版本
template <typename T>
void process(const std::vector<T>& container) {
    std::cout << "Vector specialization" << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::list<int> lst = {1, 2, 3};

    process(vec); // 调用 std::vector 特化版本
    process(lst); // 调用泛型版本

    return 0;
}
