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

}