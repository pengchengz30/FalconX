#pragma once
#include "../controllers/user_controller.hpp"
#include "../core/config_manager.hpp"
#include "../core/container.hpp"
#include "../registry/bean_registry.hpp"
#include "../registry/controller_registry.hpp"
#include "crow.h"

constexpr char CONFIG_PATH[] = "src/config/config.json";

class App {
   public:
    void run() {
        auto config = ConfigManager::load(CONFIG_PATH);
        int port = config["server"]["port"];

        crow::SimpleApp app;
        Container container;

        for (auto& reg : core::get_bean_registry()) {
            reg(container);
        }
        for (auto& reg : core::get_controller_registry()) {
            reg(app, container);
        }

        app.port(port).multithreaded().run();
    }
};
