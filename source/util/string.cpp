#include <gs/util/types.hpp>

namespace gs::util {

    uint32_t string_length(unsafe_cstr_t str) {
        uint32_t length = 0;
        if (str != nullptr) {
            while(*str != '\0') {
                str++;
                length++;
            }
        }
        return length;
    }

    bool string_any_of(unsafe_cstr_t str, char search) {
        if (str == nullptr) {
            return false;
        }
        unsafe_cstr_t it = str;

        while(*it != '\0') {
            if (*it == search)
                return true;
            it++;
        }

        return false;
    }

    int32_t string_index_of(unsafe_cstr_t str, char search) {
        if (str == nullptr) {
            return -1;
        }
        unsafe_cstr_t it = str;

        while(*it != '\0') {
            if (*it == search)
                break;
            it++;
        }

        return it - str;
    }

    int32_t string_last_index_of(unsafe_cstr_t str, char search) {
        if (str == nullptr) {
            return -1;
        }
        int32_t lastIndex = -1;
        unsafe_cstr_t it = str;

        while (*it != '\0') {
            if (*it == search) {
                lastIndex = it - str;
            }
            it++;
        }

        return lastIndex;
    }

    optional_t<uint32_t> string_parse_unsigned_int(unsafe_cstr_t str) {
        if (str == nullptr) {
            return optional_t<uint32_t>();
        }

        while (*str != '\0' && *str < 33) {
            str++;
        }

        if (*str == '\0') {
            return optional_t<uint32_t>();
        }

        uint32_t result = 0;
        bool parsed_number = false;

        while (*str != '\0' && *str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
            parsed_number = true;
        }

        if (parsed_number == false) {
            return optional_t<uint32_t>();
        }

        return optional_t<uint32_t>(result);
    }

    bool string_try_parse_unsigned_int(unsafe_cstr_t str, uint32_t& out_value) {
        if (str == nullptr) {
            return false;
        }

        while (*str != '\0' && *str < 33) {
            str++;
        }

        if (*str == '\0') {
            return false;
        }

        uint32_t result = 0;

        while (*str != '\0' && *str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
        }

        return result;
    }
}