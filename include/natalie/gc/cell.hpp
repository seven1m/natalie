#pragma once

#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "natalie/forward.hpp"
#include "natalie/macros.hpp"

namespace Natalie {

class Cell {
public:
    Cell() { }
    virtual ~Cell() { }

    void *operator new(size_t size);
    void *operator new(size_t size, void *cell) { return cell; }
    void operator delete(void *ptr);

    class Visitor {
    public:
        virtual void visit(Cell *) = 0;
        virtual void visit(const Cell *) = 0;
        virtual void visit(ValuePtr) = 0;
    };

    virtual void visit_children(Visitor &) {
    }

    // only for debugging the GC
    virtual void gc_print() {
        fprintf(stderr, "<Cell %p size=%zu>", this, sizeof(*this));
    }

    virtual bool is_collectible() {
        return true;
    }

    bool is_marked() {
        return m_marked;
    }

    void mark() {
        m_marked = true;
    }

    void unmark() {
        m_marked = false;
    }

private:
    bool m_marked { false };
};

}
