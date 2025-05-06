#pragma once
#include "container.hpp"
#include "crow.h"

class BaseController {
   protected:
    BaseController() = default;

   public:
    virtual ~BaseController() = default;

    virtual void register_routes(crow::SimpleApp& app,
                                 Container& container) = 0;

    BaseController(const BaseController&) = delete;
    BaseController& operator=(const BaseController&) = delete;
};
