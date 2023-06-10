#include <gs/system/pod.hpp>

namespace gs::util {

    uint32_t CStringLength(unsafe_cstr_t str) {
        uint32_t length = 0;
        if (str != nullptr) {
            while(*str != '\0') {
                str++;
                length++;
            }
        }
        return length;
    }

    bool CStringAnyOf(unsafe_cstr_t str, char search) {
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

    int32_t CStringIndexOf(unsafe_cstr_t str, char search) {
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

    int32_t CStringLastIndexOf(unsafe_cstr_t str, char search) {
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

    bool CStringTryParseUInt32(unsafe_cstr_t str, uint32_t& out_value) {
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