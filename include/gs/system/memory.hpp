#pragma once

#include <gs/system/pod.hpp>

namespace gs::system {

    template<typename T>
    inline size_t AddressOfPtr(const T* ptr) {
        return (size_t) ptr;
    }

    template<typename TA, typename TB>
    inline size_t PtrDistance(const TA* ptr_lower, const TB* ptr_higher) {
        return ((size_t) ptr_higher) - ((size_t) ptr_lower);
    }

    template<typename T, typename TA = T>
    inline T* SubtractPtr(const TA* ptr, size_t num_bytes) {
        return  (T*) (((uint8_t*) ptr) - num_bytes);
    }

    template<typename T, typename TA = T>
    inline T* AddPtr(const TA* ptr, size_t num_bytes) {
        return  (T*) (((uint8_t*) ptr) + num_bytes);
    }

    ptr_t AllocateMemory(size_t num_bytes, bool clear = true, bool chip = false, ptr_t comment = nullptr);

    void  ReleaseMemory(ptr_t allocated_memory);

    void CopyMemory(ptr_t dst_memory, ptr_t src_memory, size_t num_bytes);

#if defined(GS_DEBUG_MEMORY) && GS_DEBUG_MEMORY == 1
    void DebugCurrentAllocations();
#endif

}