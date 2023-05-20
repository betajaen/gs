#pragma once

namespace gs::util {
    void do_assert(const char* comment);
}

#define MUST(EXPR) (__builtin_expect(!(EXPR), 0) ? gs::util::do_assert(#EXPR) : ((void) 0))