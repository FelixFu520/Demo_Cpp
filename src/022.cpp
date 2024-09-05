#include <iostream>
#include <string>
#include <map>
#include <functional>

class ObjectFactory {
public:
    using CreateFunc = std::function<void*()>;

    static ObjectFactory& instance() {
        static ObjectFactory instance;
        return instance;
    }

    void registerClass(const std::string& className, CreateFunc func) {
        classRegistry[className] = func;
    }

    void* createObject(const std::string& className) {
        auto it = classRegistry.find(className);
        if (it != classRegistry.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::map<std::string, CreateFunc> classRegistry;
};

#define REGISTER_CLASS(className) \
    namespace { \
        class className##Helper { \
        public: \
            className##Helper() { \
                ObjectFactory::instance().registerClass(#className, []() -> void* { return new className; }); \
            } \
        }; \
        static className##Helper global_##className##Helper; \
    }

class MyClass {
public:
    void sayHello() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

REGISTER_CLASS(MyClass)

int main() {
    void* obj = ObjectFactory::instance().createObject("MyClass");
    if (obj) {
        static_cast<MyClass*>(obj)->sayHello();
        delete static_cast<MyClass*>(obj);
    }
    return 0;
}
