#pragma once

#include <gs/util/types.hpp>

namespace gs::util {

    uint32_t string_length(unsafe_cstr_t str);

    bool string_any_of(unsafe_cstr_t str, char search);

    int32_t string_index_of(unsafe_cstr_t str, char search);

    int32_t string_last_index_of(unsafe_cstr_t str, char search);

    uint32_t string_parse_unsigned_int(unsafe_cstr_t str);

    bool string_try_parse_unsigned_int(unsafe_cstr_t str, uint32_t& out_value);
}