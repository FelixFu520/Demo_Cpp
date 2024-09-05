#include <iostream>
class Base {
public:
    int value;
};

class DerivedA : virtual public Base {
public:
    void setValue(int val) {
        value = val;  // 可以直接访问
    }
};

class DerivedB : virtual public Base {
public:
    void setValue(int val) {
        value = val;  // 可以直接访问
    }
};

class DerivedC : public DerivedA, public DerivedB {
public:
    void setValue(int val) {
        DerivedA::setValue(val);  // 明确指定使用 DerivedA 的 setValue 方法
        // 或者
        // DerivedB::setValue(val);  // 如果你想要使用 DerivedB 的 setValue 方法
    }
    void display() {
        std::cout << "Value: " << DerivedA::value << std::endl;  // 明确指定路径
    }
};

int main() {
    DerivedC obj;
    obj.setValue(42);
    obj.display();  // 输出 "Value: 42"
    return 0;
}