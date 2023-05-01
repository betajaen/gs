#pragma once

#include <exec/types.h>

namespace gs {

    typedef ULONG uint32_t;
    typedef UWORD uint16_t;
    typedef UBYTE uint8_t;
    typedef LONG int32_t;
    typedef WORD int16_t;
    typedef BYTE int8_t;
    typedef APTR ptr_t;
    typedef ULONG size_t;
    typedef LONG ssize_t;
    typedef ULONG register_t;

    typedef CONST_STRPTR unsafe_cstr_t;

    enum class return_code_t : LONG;

}