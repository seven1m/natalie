#include "natalie/sexp_value.hpp"
#include "natalie.hpp"
#include "natalie/node.hpp"

namespace Natalie {

SexpValue::SexpValue(Env *env, Node *node, std::initializer_list<ValuePtr> list)
    : ArrayValue { env, list } {
    m_klass = env->Object()->const_fetch(env, "Parser")->const_fetch(env, "Sexp")->as_class();
    if (node->file())
        ivar_set(env, "@file", new StringValue { env, node->file() });
    ivar_set(env, "@line", new IntegerValue { env, static_cast<nat_int_t>(node->line()) });
    ivar_set(env, "@column", new IntegerValue { env, static_cast<nat_int_t>(node->column()) });
}

}