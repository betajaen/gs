#pragma once

#ifndef __AMIGA__
static_assert(0, "Not compiling for Amiga");
#endif
static_assert(sizeof(void*) == 4, "Pointer size is wrong");

#include <exec/types.h>

namespace gs {

    typedef ULONG uint32_t;
    typedef UWORD uint16_t;
    typedef UBYTE uint8_t;
    typedef LONG int32_t;
    typedef WORD int16_t;
    typedef BYTE int8_t;
    typedef APTR ptr_t;
    typedef LONG dosptr_t;
    typedef decltype(sizeof(0)) size_t;
    typedef LONG ssize_t;
    typedef ULONG register_t;
    typedef uint8_t byte_t;

    typedef CONST_STRPTR unsafe_cstr_t;

    constexpr dosptr_t dos_nullptr = 0UL;
}

namespace std {
    typedef gs::size_t size_t;
    typedef gs::ssize_t ptrdiff_t;
}