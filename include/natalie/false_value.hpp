#pragma once

#include <assert.h>

#include "natalie/class_value.hpp"
#include "natalie/forward.hpp"
#include "natalie/global_env.hpp"
#include "natalie/macros.hpp"
#include "natalie/symbol_value.hpp"
#include "natalie/value.hpp"

namespace Natalie {

class FalseValue : public Value {
public:
    static FalseValue *the() {
        if (s_instance)
            return s_instance;
        s_instance = new FalseValue();
        return s_instance;
    }

    ValuePtr to_s(Env *);

    virtual void gc_print() override {
        fprintf(stderr, "<FalseValue %p>", this);
    }

    virtual bool is_collectible() override {
        return false;
    }

private:
    inline static FalseValue *s_instance = nullptr;

    FalseValue()
        : Value { Value::Type::False, GlobalEnv::the()->Object()->const_fetch(SymbolValue::intern("FalseClass"))->as_class() } { }
};

}
