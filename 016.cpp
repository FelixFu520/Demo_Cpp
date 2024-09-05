#include <iostream>
#include <map>
#include <string>

#include <iostream>
#include <unordered_map>
#include <string>

void test016_1(){
     std::map<std::string, int> my_map;
    my_map["old_key"] = 42;

    // 打印原始map内容
    std::cout << "Before modification:" << std::endl;
    for (const auto& pair : my_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找并修改键
    auto it = my_map.find("old_key");
    if (it != my_map.end()) {
        int value = it->second;
        my_map.erase(it);             // 删除旧键值对
        my_map["new_key"] = value;    // 插入新键值对
    }

    // 打印修改后的map内容
    std::cout << "After modification:" << std::endl;
    for (const auto& pair : my_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
class ModifiableKeyMap {
private:
    std::map<std::string, int> data;

public:
    void insert(const std::string& key, int value) {
        data[key] = value;
    }

    bool modifyKey(const std::string& old_key, const std::string& new_key) {
        auto it = data.find(old_key);
        if (it != data.end()) {
            int value = it->second;
            data.erase(it);  // 删除旧键值对
            data[new_key] = value;  // 插入新键值对
            return true;
        }
        return false;
    }

    void print() const {
        for (const auto& pair : data) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};
int test016_2() {
    ModifiableKeyMap my_map;
    my_map.insert("old_key", 42);

    std::cout << "Before modification:" << std::endl;
    my_map.print();

    my_map.modifyKey("old_key", "new_key");

    std::cout << "After modification:" << std::endl;
    my_map.print();

    return 0;
}
class ModifiableKeyMap2 {
private:
    std::unordered_map<int, std::string> key_map;
    std::unordered_map<std::string, int> data;

public:
    void insert(int key, const std::string& value) {
        key_map[key] = value;
        data[value] = key;
    }

    bool modifyKey(int old_key, int new_key) {
        auto it = key_map.find(old_key);
        if (it != key_map.end()) {
            std::string value = it->second;
            key_map.erase(it);  // 删除旧键
            key_map[new_key] = value;  // 插入新键
            data[value] = new_key;
            return true;
        }
        return false;
    }

    void print() const {
        for (const auto& pair : key_map) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int test016_3() {
    ModifiableKeyMap2 my_map;
    my_map.insert(1, "value1");
    my_map.insert(2, "value2");

    std::cout << "Before modification:" << std::endl;
    my_map.print();

    my_map.modifyKey(1, 10);

    std::cout << "After modification:" << std::endl;
    my_map.print();

    return 0;
}

int main() {
   test016_1();

    std::cout << "----------------" << std::endl;
    test016_2();

    std::cout << "----------------" << std::endl;
    test016_3();
    return 0;
}

