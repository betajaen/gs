#pragma once

#ifndef __AMIGA__
static_assert(0, "Not compiling for Amiga");
#endif
static_assert(sizeof(void*) == 4, "Pointer size is wrong");

#if defined(PROTO_EXEC_H)
#error "Do not include proto/exec.h in headers!"
#endif

#if defined(PROTO_DOS_H)
#error "Do not include proto/dos.h in headers!"
#endif

#include <exec/types.h>

namespace gs {

    typedef ULONG uint32_t;
    typedef UWORD uint16_t;
    typedef UBYTE uint8_t;
    typedef LONG int32_t;
    typedef WORD int16_t;
    typedef BYTE int8_t;
    typedef APTR ptr_t;
    typedef LONG DosPtr;
    typedef decltype(sizeof(0)) size_t;
    typedef LONG ssize_t;
    typedef ULONG register_t;
    typedef uint8_t byte_t;

    typedef CONST_STRPTR unsafe_cstr_t;

    constexpr DosPtr dos_nullptr = 0UL;
}

namespace std {
    typedef gs::size_t size_t;
    typedef gs::ssize_t ptrdiff_t;
}