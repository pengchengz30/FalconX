// user_controller_registration.cpp
#include "../registry/auto_register_base.hpp"
#include "../registry/bean_registry.hpp"
#include "../registry/controller_registry.hpp"
#include "user_controller.hpp"

namespace {
class UserControllerAutoRegister : public AutoRegisterBase {
   public:
    UserControllerAutoRegister() { doRegister(); }

   protected:
    void registerBean() override {
        core::register_bean([](Container& c) {
            c.bind<UserController>("UserController",
                                   &UserController::getInstance());
        });
    }

    void registerController() override {
        printf("Registering UserController\n");
        core::register_controller(std::bind(
            &UserController::register_routes, &UserController::getInstance(),
            std::placeholders::_1, std::placeholders::_2));
    }
};

static UserControllerAutoRegister _reg;
}  // namespace
