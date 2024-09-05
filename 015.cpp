#include <algorithm>
#include <iostream>
#include <vector>


void test015_1(){
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    auto is_even = [](int x) { return x % 2 == 0; };
    
    auto partition_point = std::partition(numbers.begin(), numbers.end(), is_even);
    
    std::cout << "Even numbers followed by odd numbers: ";
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    




    numbers = {3, 5, 1, 4, 2, 6, 1, 9};
    auto stable_partition_point = std::stable_partition(numbers.begin(), numbers.end(), is_even);
    
    std::cout << "Even numbers followed by odd numbers, preserving order: ";
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void test015_2(){
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> even_numbers;
    std::vector<int> odd_numbers;
    auto is_even = [](int x) { return x % 2 == 0; };

    auto result = std::partition_copy(numbers.begin(), numbers.end(),
                                      std::back_inserter(even_numbers),
                                      std::back_inserter(odd_numbers),
                                      is_even);

    std::cout << "Even numbers: ";
    for (const auto& num : even_numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "Odd numbers: ";
    for (const auto& num : odd_numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

}

void test15_3(){
   int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec;

    std::copy(arr, arr + sizeof(arr)/sizeof(arr[0]), std::back_inserter(vec));

    for(int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
int main() {
    test015_1();

    std::cout << "----------------" << std::endl;
    test015_2();

    std::cout << "----------------" << std::endl;
    test15_3();
    
    return 0;
}