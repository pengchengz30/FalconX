// auto_register_base.hpp
#pragma once
#include "bean_registry.hpp"
#include "controller_registry.hpp"

class AutoRegisterBase {
   public:
    virtual ~AutoRegisterBase() = default;
    AutoRegisterBase(const AutoRegisterBase&) = delete;
    AutoRegisterBase& operator=(const AutoRegisterBase&) = delete;
    AutoRegisterBase(AutoRegisterBase&&) = delete;
    AutoRegisterBase& operator=(AutoRegisterBase&&) = delete;

   protected:
    AutoRegisterBase() = default;
    virtual void registerBean() {}
    virtual void registerController() {}

    void doRegister() {
        registerBean();
        registerController();
    }

    // static DerivedType reg
};
