#pragma once

namespace gs::util {
    void AssertAlways(const char* comment);
}

#define MUST(EXPR) (__builtin_expect(!(EXPR), 0) ? gs::util::AssertAlways(#EXPR) : ((void) 0))