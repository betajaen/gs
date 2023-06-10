#pragma once

#include <gs/system/memory.hpp>
#include <gs/util/assert.hpp>

namespace gs::util {

    template<typename T>
    struct Buffer {

    private:

        T* m_Data;
        size_t m_Capacity;

    public:

        Buffer() : m_Data{nullptr}, m_Capacity(0UL) {}

        ~Buffer() {
            release();
        }

        Buffer(const Buffer&) = delete;
        Buffer(Buffer&) = delete;
        Buffer(Buffer&&) = default;

        Buffer& operator=(const Buffer&) = delete;
        Buffer& operator=(Buffer&) = delete;
        Buffer& operator=(Buffer&&) = default;

        void release() {
            if (m_Data) {
                system::ReleaseMemory(m_Data);
                m_Capacity = 0UL;
            }
        }

        void set_capacity(size_t new_capacity) {

            if (new_capacity == m_Capacity) {
                return;
            }

            if (new_capacity == 0) {
                release();
                return;
            }

            T* new_data = system::AllocateMemory(sizeof(T) * new_capacity, false, true);
            system::CopyMemory(new_data, m_Data, sizeof(T)* m_Capacity);
            system::ReleaseMemory(m_Data);
            m_Data = new_data;
            m_Capacity = new_capacity;

        }

        size_t capacity() const {
            return m_Capacity;
        }

        T* ptr() {
            return m_Data;
        }

        const T* ptr() const {
            return m_Data;
        }

        const T& at(size_t idx) const {
            MUST(idx < m_Capacity);
            return m_Data[idx];
        }

        T& at(size_t idx) {
            MUST(idx < m_Capacity);
            return m_Data[idx];
        }

        const T& operator[](size_t idx) const {
            return at(idx);
        }

        T& operator[](size_t idx) {
            return at(idx);
        }

    };
}