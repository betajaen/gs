#pragma once

#include <gs/system/pod.hpp>

namespace gs::util {

    uint32_t CStringLength(unsafe_cstr_t str);

    bool CStringAnyOf(unsafe_cstr_t str, char search);

    int32_t CStringIndexOf(unsafe_cstr_t str, char search);

    int32_t CStringLastIndexOf(unsafe_cstr_t str, char search);

    bool CStringTryParseUInt32(unsafe_cstr_t str, uint32_t& out_value);
}