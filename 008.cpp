// https://mp.weixin.qq.com/s/26Kf7UlFSDo7K-k4duV6JQ
#include <iostream>
class Base {
public:
    Base(int value) {
        std::cout << "Base constructor: " << value << std::endl;
    }
};

class DerivedA : virtual public Base {
public:
    DerivedA() : Base(10) {}  // 这不会调用Base(int)
};

class DerivedB : virtual public Base {
public:
    DerivedB() : Base(20) {}  // 这不会调用Base(int)
};

class DerivedC : public DerivedA, public DerivedB {
public:
    DerivedC() : Base(30), DerivedA(), DerivedB() {}  // 由DerivedC来调用Base(int)
};

int main() {
    DerivedC obj;  // 仅调用Base(int)一次，输出 "Base constructor: 30"
    return 0;
}