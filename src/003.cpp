
#include <iostream>
#include <vector>
#include <typeinfo>

class Plugin {
public:
    virtual ~Plugin() {}
    virtual void execute() = 0;
};

class PluginA : public Plugin {
public:
    void execute() override {
        std::cout << "Executing PluginA" << std::endl;
    }
};

class PluginB : public Plugin {
public:
    void execute() override {
        std::cout << "Executing PluginB" << std::endl;
    }
};

void loadAndExecutePlugins(const std::vector<Plugin*>& plugins) {
    for (Plugin* plugin : plugins) {
        std::cout << "Loading plugin of type: " << typeid(*plugin).name() << std::endl;
        plugin->execute();
    }
}

int main() {
    std::vector<Plugin*> plugins;
    plugins.push_back(new PluginA());
    plugins.push_back(new PluginB());

    loadAndExecutePlugins(plugins);

    for (Plugin* plugin : plugins) {
        delete plugin;
    }
    return 0;
}