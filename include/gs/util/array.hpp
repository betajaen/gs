#pragma once

#include <gs/system/pod.hpp>
#include <gs/util/assert.hpp>

namespace gs::util {

    template<typename T, size_t Capacity>
    struct Array {
    private:
        T m_Items[Capacity];
    public:

        size_t capacity() const {
            return Capacity;
        }

        T* ptr() {
            return m_Items;
        }

        const T* ptr() const {
            return m_Items;
        }

        const T& at(size_t idx) const {
            MUST(idx < Capacity);
            return m_Items[idx];
        }

        T& at(size_t idx) {
            MUST(idx < Capacity);
            return m_Items[idx];
        }

        const T& operator[](size_t idx) const {
            return at(idx);
        }

        T& operator[](size_t idx) {
            return at(idx);
        }

    };

}