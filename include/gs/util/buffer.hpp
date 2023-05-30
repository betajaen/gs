#pragma once

#include <gs/system/memory.hpp>
#include <gs/util/assert.hpp>

namespace gs::util {

    template<typename T>
    struct buffer_t {

    private:

        T* m_data;
        size_t m_capacity;

    public:

        buffer_t() : m_data{nullptr}, m_capacity(0UL) {}

        ~buffer_t() {
            release();
        }

        buffer_t(const buffer_t&) = delete;
        buffer_t(buffer_t&) = delete;
        buffer_t(buffer_t&&) = default;

        buffer_t& operator=(const buffer_t&) = delete;
        buffer_t& operator=(buffer_t&) = delete;
        buffer_t& operator=(buffer_t&&) = default;

        void release() {
            if (m_data) {
                system::release_memory(m_data);
                m_capacity = 0UL;
            }
        }

        void set_capacity(size_t new_capacity) {

            if (new_capacity == m_capacity) {
                return;
            }

            if (new_capacity == 0) {
                release();
                return;
            }

            T* new_data = system::allocate_memory(sizeof(T) * new_capacity, false, true);
            system::copy_memory(new_data, m_data, sizeof(T)* m_capacity);
            system::release_memory(m_data);
            m_data = new_data;
            m_capacity = new_capacity;

        }

        size_t capacity() const {
            return m_capacity;
        }

        T* ptr() {
            return m_data;
        }

        const T* ptr() const {
            return m_data;
        }

        const T& at(size_t idx) const {
            MUST(idx < m_capacity);
            return m_data[idx];
        }

        T& at(size_t idx) {
            MUST(idx < m_capacity);
            return m_data[idx];
        }

        const T& operator[](size_t idx) const {
            return at(idx);
        }

        T& operator[](size_t idx) {
            return at(idx);
        }

    };
}