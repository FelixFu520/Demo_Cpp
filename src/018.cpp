#include <iostream>

void countCalls() {
    static int count = 0;  // 静态局部变量
    count++;
    std::cout << "Function called " << count << " times" << std::endl;
}
void test018_1(){
        countCalls();  // 输出: Function called 1 times
    countCalls();  // 输出: Function called 2 times
    countCalls();  // 输出: Function called 3 times
}




static int globalVar = 42;  // 静态全局变量
void printGlobalVar() {
    std::cout << "Global variable: " << globalVar << std::endl;
}
void test018_2(){
    printGlobalVar();  // 输出: Global variable: 42
    globalVar = 100;
    printGlobalVar();  // 输出: Global variable: 100
}


class MyClass {
public:
    static int staticVar;  // 声明静态成员变量
    static void printStaticVar();  // 声明静态成员函数
};
int MyClass::staticVar = 0;  // 定义静态成员变量

void MyClass::printStaticVar() {
    std::cout << "Static variable: " << staticVar << std::endl;
}

int test018_3() {
    MyClass::staticVar = 10;
    MyClass::printStaticVar();  // 输出: Static variable: 10
    MyClass::staticVar = 20;
    MyClass::printStaticVar();  // 输出: Static variable: 20
    return 0;
}





class MyClass2 {
public:
    static int staticVar;
    static void printStaticVar();
    static void setStaticVar(int value);  // 静态成员函数声明
};
int MyClass2::staticVar = 0;

void MyClass2::printStaticVar() {
    std::cout << "Static variable: " << staticVar << std::endl;
}

void MyClass2::setStaticVar(int value) {
    staticVar = value;
}
int test018_4() {
    MyClass2::setStaticVar(30);
    MyClass2::printStaticVar();  // 输出: Static variable: 30
    MyClass2::setStaticVar(40);
    MyClass2::printStaticVar();  // 输出: Static variable: 40
    return 0;
}

int main() {
    test018_1();

    std::cout<<"----------------"<<std::endl;
    test018_2();

    std::cout<<"----------------"<<std::endl;
    test018_3();

    std::cout<<"----------------"<<std::endl;
    test018_4();

    return 0;
}