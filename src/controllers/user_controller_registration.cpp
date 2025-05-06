// user_controller_registration.cpp
#include "../registry/auto_register_base.hpp"
#include "../registry/bean_registry.hpp"
#include "../registry/controller_registry.hpp"
#include "user_controller.hpp"

namespace {
class UserControllerAutoRegister : public AutoRegisterBase {
   public:
    UserControllerAutoRegister() {
        static bool constructed = false;
        if (constructed) {
            throw std::runtime_error(
                "UserControllerAutoRegister constructed more than once!");
        }
        constructed = true;
#ifdef DEBUG
        printf("UserControllerAutoRegister constructed\n");
#endif
        doRegister();
    }

   protected:
    void registerBean() override {
        core::register_bean([](Container& c) {
            c.bind<UserController>("UserController",
                                   &UserController::getInstance());
        });
    }

    void registerController() override {
#ifdef DEBUG
        printf("Registering UserController\n");
#endif
        core::register_controller(std::bind(
            &UserController::register_routes, &UserController::getInstance(),
            std::placeholders::_1, std::placeholders::_2));
    }
};

static UserControllerAutoRegister _reg;
}  // namespace
