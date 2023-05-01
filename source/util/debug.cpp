#include <gs/util/types.hpp>
#include <gs/util/string.h>


#include <proto/dos.h>
#include <proto/exec.h>

namespace gs {
    extern BPTR cli_output;

    typedef void(*dofmt_function)();
    static char temp_buffer[1024] = { 0 };
    static const uint32_t PutChar = 0x16c04e75;
    static const uint32_t LenChar = 0x52934e75;
}

namespace gs::util {


    void write_str(unsafe_cstr_t str, uint32_t str_length) {
        Write(cli_output, (APTR) str, str_length);
    }

    void write_str(unsafe_cstr_t str) {
        const uint32_t str_length = util::string_length(str);
        write_str(str, str_length);
    }

    void write_eol() {
        Write(cli_output, (APTR) "\n", 1);
    }

    void write_fmt(const char* fmt, ...) {
        ptr_t args = (ptr_t) (fmt + 1);
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(cli_output, (APTR) "<large Message>", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);

        Write(cli_output, (APTR) temp_buffer, length);
    }
}

namespace gs {

    void debug_str(const char* str) {
        Write(cli_output, (ptr_t) "D ", 2);
        Write(cli_output, (ptr_t) str, util::string_length(str));
        Write(cli_output, (ptr_t) "\n", 1);
    }


    void info_str(const char* str) {
        Write(cli_output, (ptr_t) "I ", 2);
        Write(cli_output, (ptr_t) str, util::string_length(str));
        Write(cli_output, (ptr_t) "\n", 1);
    }

    void warn_str(const char* str) {
        Write(cli_output, (ptr_t) "W ", 2);
        Write(cli_output, (ptr_t) str, util::string_length(str));
        Write(cli_output, (ptr_t) "\n", 1);
    }

    void error_str(const char* str) {
        Write(cli_output, (ptr_t) "W ", 2);
        Write(cli_output, (ptr_t) str, util::string_length(str));
        Write(cli_output, (ptr_t) "\n", 1);
    }


    void debug_fmt(const char* fmt, ...) {
        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(cli_output, (APTR) "D <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);

        Write(cli_output, (ptr_t) "D ", 2);
        Write(cli_output, (APTR) temp_buffer, length);
        Write(cli_output, (ptr_t) "\n", 1);
    }

    void info_fmt(const char* fmt, ...) {
        static const auto prefix = "I ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(cli_output, (APTR) "I <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);

        Write(cli_output, (ptr_t) "I ", 2);
        Write(cli_output, (APTR) temp_buffer, length);
        Write(cli_output, (ptr_t) "\n", 1);
    }

    void warn_fmt(const char* fmt, ...) {
        static const auto prefix = "W ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(cli_output, (APTR) "W <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);

        Write(cli_output, (ptr_t) "W ", 2);
        Write(cli_output, (APTR) temp_buffer, length);
        Write(cli_output, (ptr_t) "\n", 1);
    }

    void error_fmt(const char* fmt, ...) {
        static const auto prefix = "E ";
        static const auto suffix = "\n";

        ptr_t args = (ptr_t) ((uint8_t*) &fmt + sizeof(fmt));
        uint32_t length = 0;

        RawDoFmt(fmt, args, (dofmt_function)&LenChar, &length);
        if (length >= sizeof(temp_buffer)) {
            Write(cli_output, (APTR) "E <large Message>\n", 15);
            return;
        }

        RawDoFmt(fmt, args, (dofmt_function)&PutChar, temp_buffer);

        Write(cli_output, (ptr_t) "E ", 2);
        Write(cli_output, (APTR) temp_buffer, length);
        Write(cli_output, (ptr_t) "\n", 1);
    }
}