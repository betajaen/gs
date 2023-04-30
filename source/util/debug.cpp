#include <gs/util/types.hpp>
#include <gs/util/string.h>

#include <proto/dos.h>
#include <proto/exec.h>

namespace gs::hw {
    extern BPTR cli_output;
}

namespace gs::util {

    void write_str(unsafe_cstr_t str, uint32_t str_length) {
        Write(hw::cli_output, (APTR) str, str_length);
    }

    void write_str(unsafe_cstr_t str) {
        const uint32_t str_length = string_length(str);
        write_str(str, str_length);
    }

    void write_eol() {
        static const auto eol = "\n";
        Write(hw::cli_output, (APTR) eol, 1);
    }

}