#include <gs/system/file.hpp>
#include <proto/dos.h>

namespace gs::system {

    bool ReadFile::OpenFile(unsafe_cstr_t path) {
        if (m_Handle != dos_nullptr) {
            Close(m_Handle);
        }

        m_Handle = Open(path, MODE_OLDFILE);
    }

    void ReadFile::CloseFile() {
        if (m_Handle != dos_nullptr) {
            Close(m_Handle);
        }
    }

    bool ReadFile::TryRead(void* data, size_t size) {
        Read(m_Handle, data, size);
    }

    bool WriteFile::OpenFile(unsafe_cstr_t path) {
        if (m_Handle != dos_nullptr) {
            Close(m_Handle);
        }

        m_Handle = Open(path, MODE_NEWFILE);
    }

    void WriteFile::CloseFile() {
        if (m_Handle != dos_nullptr) {
            Close(m_Handle);
        }
    }

    void WriteFile::TryWrite(const void* data, size_t size) {
        Write(m_Handle, (APTR) data, size);
    }
}