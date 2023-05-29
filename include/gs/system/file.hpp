#pragma once

#include <gs/util/pod.hpp>

namespace gs::system {

    struct read_file_t {
    private:
        dosptr_t handle = dos_nullptr;
    public:
        read_file_t() = default;

        inline ~read_file_t() {
            close();
        }

        read_file_t(const read_file_t&) = delete;
        read_file_t(read_file_t&&) = default;

        read_file_t& operator=(const read_file_t&) = default;
        read_file_t& operator=(read_file_t&&) = default;

        inline bool is_open() const {
            return handle != dos_nullptr;
        }

        bool open(unsafe_cstr_t path);

        void close();

        bool try_read(void* data, size_t size);

        template<typename T>
        bool read(T& value) {
            return try_read(&value, sizeof(T));
        }
    };

    struct write_file_t {
    private:
        dosptr_t handle = dos_nullptr;
    public:
        write_file_t() = default;

        inline ~write_file_t() {
            close();
        }

        write_file_t(const write_file_t&) = delete;
        write_file_t(write_file_t&&) = default;

        write_file_t& operator=(const write_file_t&) = default;
        write_file_t& operator=(write_file_t&&) = default;

        inline bool is_open() const {
            return handle != dos_nullptr;
        }

        bool open(unsafe_cstr_t path);

        void close();

        void try_write(const void* data, size_t size);

        template<typename T>
        void write(const T& value) {
            try_write(&value, sizeof(T));
        }
    };

}