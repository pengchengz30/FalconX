#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "../core/container.hpp"

namespace core {

using BeanRegisterFunc = std::function<void(Container&)>;

inline std::vector<BeanRegisterFunc>& get_bean_registry() {
    static std::vector<BeanRegisterFunc> registry;
    return registry;
}

inline void register_bean(BeanRegisterFunc func) {
    get_bean_registry().push_back(std::move(func));
#ifdef DEBUG
    printf("get_bean_registry() size: %zu\n", get_bean_registry().size());
#endif
}
}  // namespace core
