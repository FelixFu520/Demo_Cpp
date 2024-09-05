// https://mp.weixin.qq.com/s/26Kf7UlFSDo7K-k4duV6JQ
#include <iostream>

// 基类
class Base {
public:
    int baseValue;
};

// 派生类A，虚继承自Base
class DerivedA : virtual public Base {
public:
    void setAValue(int val) {
        baseValue = val;
    }
};

// 派生类B，虚继承自Base
class DerivedB : virtual public Base {
public:
    void setBValue(int val) {
        baseValue = val;
    }
};

// 最终派生类C，继承自DerivedA和DerivedB
class DerivedC : public DerivedA, public DerivedB {
public:
    void display() const {
        std::cout << "Base value: " << baseValue << std::endl;
    }
};

int main() {
    DerivedC obj;
    obj.setAValue(10);
    obj.display();  // 输出 "Base value: 10"
    obj.setBValue(20);
    obj.display();  // 输出 "Base value: 20"
    
    return 0;
}