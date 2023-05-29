#include <gs/util/types.hpp>
#include <gs/util/memory.hpp>
#include <gs/system/debug.hpp>

#include <proto/exec.h>

namespace gs::util {

    struct allocation_t;
    struct allocation_footer_t;

    struct allocation_footer_t {
        allocation_t* allocation;
    };

    struct allocation_t {
#if defined(gs_debug_memory) && gs_debug_memory == 1
        allocation_t *next, *prev;
#endif
        ptr_t comment;
        allocation_footer_t* footer;
    };


#if defined(gs_debug_memory) && gs_debug_memory == 1

    static allocation_t *g_head_allocation = nullptr, *g_tail_allocation = nullptr;
    static uint32_t g_max_allocations = 0, g_current_allocations = 0;

    void push_tracked_allocation(allocation_t* allocation) {

        g_current_allocations++;
        if (g_current_allocations >= g_max_allocations)
            g_max_allocations = g_current_allocations;

        if (g_head_allocation == nullptr) {
            g_head_allocation = g_tail_allocation = allocation;
            allocation->prev = allocation->next = nullptr;
        }
        else {
            g_tail_allocation->next = allocation;
            allocation->prev = g_tail_allocation;
            g_tail_allocation = allocation;
        }

    }

    void pop_tracked_allocation(allocation_t* allocation) {

        if (g_current_allocations == 0) {
            WARN_STR("Allocation released twice!");
            return;
        }

        g_current_allocations--;

        if (g_head_allocation == allocation && g_tail_allocation == allocation) {
            g_head_allocation = nullptr;
            g_tail_allocation = nullptr;
        }
        else if (g_head_allocation == allocation) {
            g_head_allocation = allocation->next;
            g_head_allocation->prev = nullptr;
        }
        else if (g_tail_allocation == allocation) {
            g_tail_allocation = allocation->prev;
            g_tail_allocation->next = nullptr;
        }
        else {
            allocation_t* after = allocation->next;
            allocation_t* before = allocation->prev;
            after->prev = before;
            before->next = after;
        }

        allocation->next = nullptr;
        allocation->prev = nullptr;

    }

    void debug_allocations() {

        allocation_t* allocation = g_head_allocation;
        uint32_t counter = 0;
        while(allocation != nullptr) {
            ptr_t user = ptr_add<ptr_t>(allocation, sizeof(allocation_t));
            size_t size = ptr_length(user, allocation->footer);
            DEBUG_FMT("%lu. 0x%08lx %lu %lx", counter, (size_t) user, size, allocation->comment);
            counter++;
            allocation = allocation->next;
        }
        DEBUG_FMT("%lu total allocations of %lu maximum.", counter, g_max_allocations);

    }

    bool check_for_allocation(allocation_t* test) {
        allocation_t* allocation = g_head_allocation;
        while(allocation != nullptr) {
            if (allocation == test)
                return true;

            allocation = allocation->next;
        }
        return false;
    }

#endif

    bool check_allocation_guards(void* allocated_memory) {
        allocation_t* allocation = ptr_subtract<allocation_t>(allocated_memory, sizeof(allocation_t));
        allocation_footer_t* footer = allocation->footer;

#if defined(gs_debug_memory) && gs_debug_memory == 1
        // double free
        if (check_for_allocation(allocation) == false) {
            WARN_FMT("Double free for %p.", allocated_memory);
            return false;
        }
#endif

        // guard overwrite or underwrite!
        if (footer->allocation != allocation) {
            WARN_FMT("Over or underwrite detected %p.", allocated_memory);
            return false;
        }

        return true;
    }

    ptr_t allocate_memory(size_t num_bytes, bool clear, bool chip, ptr_t comment) {
        ULONG requirements = MEMF_ANY;

        if (clear)
            requirements |= MEMF_CLEAR;
        if (chip)
            requirements |= MEMF_CHIP;

        num_bytes = (num_bytes + 3) & ~3;
        size_t total_size = sizeof(allocation_t) + sizeof(allocation_footer_t) + num_bytes;
        ptr_t memory_block = AllocVec(total_size, requirements);

        if (memory_block == nullptr) {
            ERROR_FMT("Could not allocate %lu bytes.", num_bytes);
            return nullptr;
        }

        allocation_t* allocation = (allocation_t*) memory_block;
        allocation->comment = comment;
        allocation_footer_t* footer = (allocation_footer_t*) ((uint8_t*) memory_block + sizeof(allocation_t) + num_bytes);
        footer->allocation = allocation;
        allocation->footer = footer;

#if defined(gs_debug_memory) && gs_debug_memory == 1
        push_tracked_allocation(allocation);
#endif

        ptr_t user = (ptr_t) ((uint8_t*) memory_block + sizeof(allocation_t));

        return user;
    }

    void  release_memory(ptr_t allocated_memory) {

        if (allocated_memory == nullptr) {
            WARN_STR("null pointer freed.");
            return;
        }

        if (check_allocation_guards(allocated_memory) == false) {
            return;
        }

        allocation_t* allocation = ptr_subtract<allocation_t>(allocated_memory, sizeof(allocation_t));

#if defined(gs_debug_memory) && gs_debug_memory == 1
        pop_tracked_allocation(allocation);
#endif

        FreeVec(allocation);
    }

}