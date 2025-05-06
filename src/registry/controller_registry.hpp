#pragma once
#include <functional>
#include <vector>

#include "../core/container.hpp"
#include "crow.h"

namespace core {

using ControllerRegisterFunc =
    std::function<void(crow::SimpleApp&, Container&)>;

inline std::vector<ControllerRegisterFunc>& get_controller_registry() {
    static std::vector<ControllerRegisterFunc> registry;
    return registry;
}

inline void register_controller(ControllerRegisterFunc func) {
    get_controller_registry().push_back(std::move(func));
#ifdef DEBUG
    printf("get_controller_registry() size: %zu\n",
           get_controller_registry().size());
#endif
}
}