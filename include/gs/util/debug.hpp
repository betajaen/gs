#pragma once

#include <gs/util/types.hpp>

namespace gs::util {

    void write_str(unsafe_cstr_t str, uint32_t str_length);
    void write_str(unsafe_cstr_t str);
    void write_fmt(unsafe_cstr_t fmt, ...);
    void write_eol();
}

namespace gs {
    void debug(const char* str) {
        gs::util::write_str("D ", 2);
        gs::util::write_str(str);
        gs::util::write_eol();
    }

    void info(const char* str) {
        gs::util::write_str("  ", 2);
        gs::util::write_str(str);
        gs::util::write_eol();
    }

    void warn(const char* str) {
        gs::util::write_str("W ", 2);
        gs::util::write_str(str);
        gs::util::write_eol();
    }

    void error(const char* str) {
        gs::util::write_str("E ", 2);
        gs::util::write_str(str);
        gs::util::write_eol();
    }

    template<typename ...T>
    void debug(const char* str, T... args) {
        gs::util::write_str("D ", 2);
        gs::util::write_fmt(str, args...);
        gs::util::write_eol();
    }

    template<typename ...T>
    void info(const char* str, T... args) {
        gs::util::write_str("  ", 2);
        gs::util::write_fmt(str, args...);
        gs::util::write_eol();
    }

    template<typename ...T>
    void warn(const char* str, T... args) {
        gs::util::write_str("W ", 2);
        gs::util::write_fmt(str, args...);
        gs::util::write_eol();
    }

    template<typename ...T>
    void error(const char* str, T... args) {
        gs::util::write_str("E ", 2);
        gs::util::write_fmt(str, args...);
        gs::util::write_eol();
    }
}
