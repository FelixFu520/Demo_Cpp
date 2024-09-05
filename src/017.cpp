#include <iostream>
#include <map>
#include <chrono>

int main() {
    std::map<int, int> myMap;

    // 使用 operator[]
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        myMap[i] = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken by operator[]: " << elapsed.count() << " seconds" << std::endl;

    // 使用 insert()
    myMap.clear();
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        myMap.insert(std::make_pair(i, i));
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Time taken by insert(): " << elapsed.count() << " seconds" << std::endl;

    return 0;
}