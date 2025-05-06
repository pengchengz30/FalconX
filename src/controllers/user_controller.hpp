#pragma once
#include "../core/base_controller.hpp"
#include "../core/container.hpp"
#include "../registry/controller_registry.hpp"
#include "../utils/response_util.hpp"
#include "crow.h"

class UserController : public BaseController {
   public:
    static UserController& getInstance() {
        static UserController instance;
        return instance;
    }

    crow::response get(const crow::request& req) {
        crow::json::wvalue user;
        user["id"] = 1;
        user["name"] = "Alice";
        return ResponseUtil::ok(std::move(user));
    }

    void register_routes(crow::SimpleApp& app, Container& container) override {
        auto ctrl = container.get<UserController>("UserController");
        CROW_ROUTE(app, "/user")(
            [ctrl](const crow::request& req) { return ctrl->get(req); });
    }

   private:
    UserController() = default;
    UserController(const UserController&) = delete;
    UserController& operator=(const UserController&) = delete;
};
