#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void derivedFunction() {
        std::cout << "Derived function called" << std::endl;
    }
};

int main() {
    Base* base = new Derived();  // 实际类型是 Derived
    Derived* derived = dynamic_cast<Derived*>(base);

    if (derived) {
        derived->derivedFunction();
    } else {
        std::cout << "Conversion failed" << std::endl;
    }

    delete base;
    return 0;
}
