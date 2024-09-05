
#include <iostream>
#include <string>
#include <string_view>
void printString(std::string_view str) {
    std::cout << str << std::endl;
}
int main() {
    std::string original = "Hello, string_view!";
    printString(original); // 不会复制original，直接引用
    printString("直接使用字面量"); // 同样有效

    return 0;
}