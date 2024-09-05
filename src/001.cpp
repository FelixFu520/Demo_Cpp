#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}  // 确保有虚函数表
};

class Derived : public Base {};

int main() {
    Base* base = new Base();
    Base* derived = new Derived();

    std::cout << "base is of type: " << typeid(*base).name() << std::endl;
    std::cout << "derived is of type: " << typeid(*derived).name() << std::endl;

    delete base;
    delete derived;
    return 0;
}