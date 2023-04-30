#include <gs/util/types.hpp>
#include <gs/util/string.h>


#include <proto/dos.h>
#include <proto/exec.h>


namespace gs::hw {
    extern BPTR cli_output;
}

namespace gs {

    typedef void(*dofmt_function)();
    static char temp_buffer[1024] = { 0 };
    static const uint32_t PutChar = 0x16c04e75;
    static const uint32_t LenChar = 0x52934e75;

    void write_str(unsafe_cstr_t str, uint32_t str_length) {
        Write(hw::cli_output, (APTR) str, str_length);
    }

    void write_str(unsafe_cstr_t str) {
        const uint32_t str_length = util::string_length(str);
        write_str(str, str_length);
    }

    void write_eol() {
        static const auto eol = "\n";
        Write(hw::cli_output, (APTR) eol, 1);
    }

    void write_fmt(const char* fmt, ...) {
        ptr_t args = (ptr_t) (fmt + 1);
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(hw::cli_output, (APTR) "<large Message>", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);
        temp_buffer[length] = '\0';

        Write(hw::cli_output, (APTR) temp_buffer, length);
    }
}

namespace gs {

    void debug_str(const char* str) {
        static const auto prefix = "D ";
        static const auto suffix = "\n";
        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (ptr_t) str, util::string_length(str));
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }


    void info_str(const char* str) {
        static const auto prefix = "I ";
        static const auto suffix = "\n";
        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (ptr_t) str, util::string_length(str));
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }

    void warn_str(const char* str) {
        static const auto prefix = "W ";
        static const auto suffix = "\n";
        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (ptr_t) str, util::string_length(str));
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }

    void error_str(const char* str) {
        static const auto prefix = "E ";
        static const auto suffix = "\n";
        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (ptr_t) str, util::string_length(str));
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }


    void debug_fmt(const char* fmt, ...) {
        static const auto prefix = "D ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(hw::cli_output, (APTR) "D <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);
        temp_buffer[length] = '\0';

        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (APTR) temp_buffer, length);
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }

    void info_fmt(const char* fmt, ...) {
        static const auto prefix = "I ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(hw::cli_output, (APTR) "I <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);
        temp_buffer[length] = '\0';

        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (APTR) temp_buffer, length);
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }

    void warn_fmt(const char* fmt, ...) {
        static const auto prefix = "W ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(hw::cli_output, (APTR) "W <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);
        temp_buffer[length] = '\0';

        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (APTR) temp_buffer, length);
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }

    void error_fmt(const char* fmt, ...) {
        static const auto prefix = "E ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(hw::cli_output, (APTR) "E <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);
        temp_buffer[length] = '\0';

        Write(hw::cli_output, (ptr_t) prefix, sizeof(prefix));
        Write(hw::cli_output, (APTR) temp_buffer, length);
        Write(hw::cli_output, (ptr_t) suffix, sizeof(suffix));
    }
}