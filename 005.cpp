// https://mp.weixin.qq.com/s/26Kf7UlFSDo7K-k4duV6JQ
#include <iostream>

// 基类
class Base {
public:
    virtual void display() const {
        std::cout << "Base class display function." << std::endl;
    }
};

// 派生类
class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived class display function." << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    
    // 通过基类指针调用虚函数
    basePtr->display();  // 输出 "Derived class display function."
    
    return 0;
}