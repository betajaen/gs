#pragma once

#include <gs/util/pod.hpp>
#include <gs/util/meta/sizes.hpp>
#include <gs/util/meta/equality.hpp>

namespace gs::util {
    template<typename T>
    constexpr T&& move(T& arg) {
        return static_cast<T&&>(arg);
    }

    template<typename T>
    void swap(T& a, T& b) {
        T temp = move(a);
        a = move(b);
        b = move(temp);
    }

    void copy_memory(void* dst, const void* src, size_t size);

    void zero_memory(void* dst, size_t size);
}

namespace gs::util::meta {

    template<typename T, typename T0>
    size_t copy_into(const T& value, void* data) {
        if (same<T, T0>()) {
            new (data) T0(value);
            return 0;
        }
        else {
            return 1;
        }
    }

    template<typename T, typename T0>
    size_t move_into(T&& value, void* data) {
        if (same<T, T0>()) {
            new (data) T0(move(value));
            return 0;
        }
        else {
            return 1;
        }
    }

    template<typename T0>
    size_t copy_into(void* dst_data, size_t& dst_index, void* src_data, size_t src_index) {
        if (src_index == 0) {
            ((T0*) dst_data) = ((T0*) src_data);
            return 0;
        }
        else {
            return 1;
        }
    }

    template<typename ...TArgs>
    void move_into(void* dst_data, size_t& dst_index, void* src_data, size_t& src_index, size_t data_size) {
        copy_memory(dst_data, src_data, data_size);
        dst_index = src_index;
        zero_memory(src_data, data_size);
        src_index = count<TArgs...>();
    }



}