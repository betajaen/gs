#pragma once

#include <gs/system/pod.hpp>

namespace gs::system {

    struct ReadFile {
    private:
        DosPtr m_Handle = dos_nullptr;
    public:
        ReadFile() = default;

        inline ~ReadFile() {
            CloseFile();
        }

        ReadFile(const ReadFile&) = delete;
        ReadFile(ReadFile&&) = default;

        ReadFile& operator=(const ReadFile&) = default;
        ReadFile& operator=(ReadFile&&) = default;

        inline bool IsOpen() const {
            return m_Handle != dos_nullptr;
        }

        bool OpenFile(unsafe_cstr_t path);

        void CloseFile();

        bool TryRead(void* data, size_t size);

        template<typename T>
        bool Read(T& value) {
            return TryRead(&value, sizeof(T));
        }
    };

    struct WriteFile {
    private:
        DosPtr m_Handle = dos_nullptr;
    public:
        WriteFile() = default;

        inline ~WriteFile() {
            CloseFile();
        }

        WriteFile(const WriteFile&) = delete;
        WriteFile(WriteFile&&) = default;

        WriteFile& operator=(const WriteFile&) = default;
        WriteFile& operator=(WriteFile&&) = default;

        inline bool IsOpen() const {
            return m_Handle != dos_nullptr;
        }

        bool OpenFile(unsafe_cstr_t path);

        void CloseFile();

        void TryWrite(const void* data, size_t size);

        template<typename T>
        void Write(const T& value) {
            TryWrite(&value, sizeof(T));
        }
    };

}