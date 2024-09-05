
#include <iostream>
#include <utility>
#include <memory>

void process(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

template <typename T>
void forward_example(T&& arg) {
    process(std::forward<T>(arg));
}

void test01(){
    int a = 10;
    forward_example(a);           // 传递左值
    forward_example(20);          // 传递右值
}

class MyClass {
public:
    MyClass(int x) { std::cout << "MyClass constructor: " << x << std::endl; }
};

template <typename T, typename... Args>
std::unique_ptr<T> make_unique_forward(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

void test02(){
    auto my_obj = make_unique_forward<MyClass>(42);
}


void print() {
    std::cout << "End of variadic template." << std::endl;
}

template <typename T, typename... Args>
void print(T&& first, Args&&... args) {
    std::cout << "Argument: " << first << std::endl;
    print(std::forward<Args>(args)...);
}

void test03(){
     print(1, 2.5, "hello");
}
int main() {

    test01();

    std::cout<<"-----------------"<<std::endl;
    test02();

    std::cout<<"-----------------"<<std::endl;
    test03();
    return 0;
}