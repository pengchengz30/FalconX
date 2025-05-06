#pragma once
#include <fstream>

#include "nlohmann/json.hpp"

class ConfigManager {
   public:
    static nlohmann::json load(const std::string& path) {
        std::ifstream in(path);
        nlohmann::json config;
        in >> config;
        return config;
    }
};