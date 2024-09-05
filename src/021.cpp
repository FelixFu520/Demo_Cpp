
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base* base = new Derived();
    std::cout << "Type: " << typeid(*base).name() << std::endl;
    delete base;
    return 0;
}
