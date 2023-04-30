#pragma once

#include <gs/util/types.hpp>

namespace gs::util {

    void write_str(unsafe_cstr_t str, uint32_t str_length);
    void write_str(unsafe_cstr_t str);
    void write_fmt(unsafe_cstr_t fmt, ...);
    void write_eol();
}

namespace gs {

    void debug_str(const char* str);
    void info_str(const char* str);
    void warn_str(const char* str);
    void error_str(const char* str);

    void debug_fmt(const char* fmt, ...);
    void info_fmt(const char* fmt, ...);
    void warn_fmt(const char* fmt, ...);
    void error_fmt(const char* fmt, ...);

}
