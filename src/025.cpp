#include <iostream>
#include <optional>

std::optional<int> findEven(int num) {
    if (num % 2 == 0) {
        return num; // 返回偶数
    }
    return std::nullopt; // 返回空对象
}

std::optional<int> stringToInt(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (...) {
        return std::nullopt;
    }
}

int main() {
    auto result = findEven(4);
    
    if (result.has_value()) {
        std::cout << "Even number: " << result.value() << std::endl;
    } else {
        std::cout << "No even number found." << std::endl;
    }

    auto number = stringToInt("f");
    if (number) {
        std::cout << "Converted number: " << *number << std::endl;
    } else {
        std::cout << "Invalid string for conversion." << std::endl;
    }


    return 0;
}
