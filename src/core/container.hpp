#pragma once
#include <stdexcept>
#include <string>
#include <unordered_map>

class Container {
   private:
    std::unordered_map<std::string, void*> instances;

   public:
    template <typename T>
    void bind(const std::string& name, T* instance) {
        instances[name] = static_cast<void*>(instance);
    }

    template <typename T>
    T* get(const std::string& name) const {
        auto it = instances.find(name);
        if (it == instances.end()) {
            throw std::runtime_error("Service not found: " + name);
        }
        return static_cast<T*>(it->second);
    }
};
