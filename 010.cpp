// https://mp.weixin.qq.com/s?__biz=MzkzMTY3NDYwNQ==&mid=2247484613&idx=1&sn=928eb30710876a65f9feca395dc4882f&chksm=c2662447f511ad5184944618100bc8eebad8a98c9a59ad736301e6725afaf04741c9b0fbc861&cur_album_id=3386784075163844618&scene=189#wechat_redirect

#include <iostream>

class MyClass {
public:
    void memberFunction1() {
        std::cout << "memberFunction1 called" << std::endl;
    }

    void memberFunction2(int x) {
        std::cout << "memberFunction2 called with " << x << std::endl;
    }
};

int main() {
    MyClass obj;
    MyClass* pObj = &obj;

    // 定义指向 MyClass::memberFunction1 的指针
    void (MyClass::*ptr1)() = &MyClass::memberFunction1;
    // 定义指向 MyClass::memberFunction2 的指针
    void (MyClass::*ptr2)(int) = &MyClass::memberFunction2;

    // 使用对象调用成员函数指针
    (obj.*ptr1)();  // 输出：memberFunction1 called

    // 使用对象指针调用成员函数指针
    (pObj->*ptr2)(42);  // 输出：memberFunction2 called with 42

    return 0;
}