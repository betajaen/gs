#include <gs/system/file.hpp>
#include <proto/dos.h>

namespace gs::system {

    bool read_file_t::open(unsafe_cstr_t path) {
        if (handle != dos_nullptr) {
            Close(handle);
        }

        handle = Open(path, MODE_OLDFILE);
    }

    void read_file_t::close() {
        if (handle != dos_nullptr) {
            Close(handle);
        }
    }

    bool read_file_t::try_read(void* data, size_t size) {
        Read(handle, data, size);
    }


    bool write_file_t::open(unsafe_cstr_t path) {
        if (handle != dos_nullptr) {
            Close(handle);
        }

        handle = Open(path, MODE_NEWFILE);
    }

    void write_file_t::close() {
        if (handle != dos_nullptr) {
            Close(handle);
        }
    }

    void write_file_t::try_write(const void* data, size_t size) {
        Write(handle, (APTR) data, size);
    }
}