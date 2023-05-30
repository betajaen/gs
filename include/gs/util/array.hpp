#pragma once

#include <gs/system/pod.hpp>
#include <gs/util/assert.hpp>

namespace gs::util {

    template<typename T, size_t Capacity>
    struct array_t {
    private:
        T items[Capacity];
    public:

        size_t capacity() const {
            return Capacity;
        }

        T* ptr() {
            return items;
        }

        const T* ptr() const {
            return items;
        }

        const T& at(size_t idx) const {
            MUST(idx < Capacity);
            return items[idx];
        }

        T& at(size_t idx) {
            MUST(idx < Capacity);
            return items[idx];
        }

        const T& operator[](size_t idx) const {
            return at(idx);
        }

        T& operator[](size_t idx) {
            return at(idx);
        }

    };

}