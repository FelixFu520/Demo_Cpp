

#include <iostream>
#include <vector>

auto add(int a, int b) -> decltype(a + b) {
    return a + b;
}

void test019_1(){
        int a = 5;
    decltype(a) b = 10; // b 的类型是 int
    std::cout << "Type of b is int: " << std::boolalpha << std::is_same<decltype(b), int>::value << std::endl;

        int result = add(5, 10); // result 的类型是 int
    std::cout << "Result of add(5, 10) is: " << result << std::endl;
}


class Example {
public:
    std::vector<int> vec;
    
    decltype(vec.begin()) begin() {
        return vec.begin();
    }
};
int test019_2() {
    Example ex;
    ex.vec = {1, 2, 3};
    auto it = ex.begin(); // it 的类型是 std::vector<int>::iterator
    std::cout << "First element is: " << *it << std::endl;
    return 0;
}


decltype(auto) foo() {
    int x = 10;
    return x; // 返回类型是 int
}
int test019_3() {
    auto result = foo();
    std::cout << "Result of foo() is: " << result << std::endl;
    return 0;
}


int main() {

    test019_1();

    std::cout << "-----------------" <<std::endl;
    test019_2();

    std::cout << "-----------------" <<std::endl;
    test019_3();
    return 0;
}