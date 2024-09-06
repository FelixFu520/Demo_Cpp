#include <fstream>
#include <iostream>
#include <string>

int t1() {
    // 标准输出
    std::cout << "Hello, World!" << std::endl;

    // 标准输入
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;

    return 0;
}
int t2() {
    std::ifstream inputFile("example.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return 0;
}
int t3() {
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    outputFile << "This is a line in the file." << std::endl;
    outputFile << "This is another line in the file." << std::endl;

    outputFile.close();
    return 0;
}
int t4() {
    std::string input = "123 45.67 Hello";
    std::istringstream inputStream(input);

    int intValue;
    double doubleValue;
    std::string strValue;

    inputStream >> intValue >> doubleValue >> strValue;

    std::cout << "Integer: " << intValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;
    std::cout << "String: " << strValue << std::endl;

    return 0;
}
int t5() {
    std::ostringstream outputStream;

    int intValue = 123;
    double doubleValue = 45.67;
    std::string strValue = "Hello";

    outputStream << "Integer: " << intValue << ", "
                 << "Double: " << doubleValue << ", "
                 << "String: " << strValue;

    std::string formattedString = outputStream.str();
    std::cout << "Formatted String: " << formattedString << std::endl;

    return 0;
}

int main() {
    t1();
    t2();
    t3();
    t4();
    t5();
    return 0;
}