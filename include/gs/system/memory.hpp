#pragma once

#include <gs/system/pod.hpp>

namespace gs::system {

    template<typename T>
    inline size_t ptr_address(const T* ptr) {
        return (size_t) ptr;
    }

    template<typename TA, typename TB>
    inline size_t ptr_length(const TA* ptr_lower, const TB* ptr_higher) {
        return ((size_t) ptr_higher) - ((size_t) ptr_lower);
    }

    template<typename T, typename TA = T>
    inline T* ptr_subtract(const TA* ptr, size_t num_bytes) {
        return  (T*) (((uint8_t*) ptr) - num_bytes);
    }

    template<typename T, typename TA = T>
    inline T* ptr_add(const TA* ptr, size_t num_bytes) {
        return  (T*) (((uint8_t*) ptr) + num_bytes);
    }

    ptr_t allocate_memory(size_t num_bytes, bool clear = true, bool chip = false, ptr_t comment = nullptr);

    void  release_memory(ptr_t allocated_memory);

#if defined(gs_debug_memory) && gs_debug_memory == 1
    void debug_allocations();
#endif

}