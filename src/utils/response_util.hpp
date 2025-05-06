#pragma once
#include <string>

#include "crow.h"

class ResponseUtil {
   public:
    static crow::response ok(crow::json::wvalue&& data) {
        crow::json::wvalue res;
        res["code"] = 200;
        res["message"] = "OK";
        res["data"] = std::move(data);
        return crow::response{res};
    }
    static crow::response error(int code, const std::string& message) {
        crow::json::wvalue res;
        res["code"] = code;
        res["message"] = message;
        res["data"] = nullptr;
        return crow::response{res};
    }
};
