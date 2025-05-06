#pragma once
#include "../controllers/user_controller.hpp"
#include "container.hpp"
#include "crow.h"

class RouteRegistrar {
   public:
    static void register_all(crow::SimpleApp& app, Container& container) {
        UserController::register_routes(app, container);
    }
};
