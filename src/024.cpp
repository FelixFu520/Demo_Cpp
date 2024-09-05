
#include <iostream>
#include <variant>
#include <string>

// 定义一个 std::variant，可以存储 int、double 或 std::string
using MyVariant = std::variant<int, double, std::string>;

// 定义一个访问者类
struct MyVisitor {
    void operator()(int i) const {
        std::cout << "Visited int: " << i << std::endl;
    }

    void operator()(double d) const {
        std::cout << "Visited double: " << d << std::endl;
    }

    void operator()(const std::string& s) const {
        std::cout << "Visited string: " << s << std::endl;
    }
};

int main() {
    MyVariant var;

    // 初始化为 int
    var = 42;
    std::cout << "Initial value (int): " << std::get<int>(var) << std::endl;

    // 使用 std::visit 访问和处理存储的值
    std::visit(MyVisitor(), var);

    // 重新赋值为 double
    var = 3.14;
    std::cout << "New value (double): " << std::get<double>(var) << std::endl;
    std::visit(MyVisitor(), var);

    // 重新赋值为 std::string
    var = std::string("Hello, world!");
    std::cout << "New value (string): " << std::get<std::string>(var) << std::endl;
    std::visit(MyVisitor(), var);

    return 0;
}