// https://mp.weixin.qq.com/s/26Kf7UlFSDo7K-k4duV6JQ
#include <iostream>
class Base {
public:
    Base() {
        display();  // 调用Base::display()
    }
    virtual void display() const {
        std::cout << "Base class display function." << std::endl;
    }
    virtual ~Base() {
        display();  // 调用Base::display()
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived class display function." << std::endl;
    }
};

int main() {
    Derived d;  // 在构造和析构期间调用Base::display
    return 0;
}
