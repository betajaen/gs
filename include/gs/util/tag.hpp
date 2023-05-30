#pragma once

#include <gs/util/pod.hpp>

namespace gs::util {

    typedef uint32_t tag_name_t;

    union tag_item_u {
      uint8_t ub;
      uint16_t uw;
      uint32_t ul;
      int8_t b;
      int16_t w;
      int32_t l;
      const char* cstr;
      char* str;
      ptr_t ptr;
    };

    static_assert(sizeof(tag_item_u) == 4, "pod_variant_u was expected to be 4 bytes in size.");

    struct tag_item_t {
      uint32_t   name;
      tag_item_u value;

      tag_item_t(uint32_t n) : name{n} { value.ul = 0UL; }
      tag_item_t(uint32_t n, uint8_t v) : name{n} { value.ub = v; }
      tag_item_t(uint32_t n, uint16_t v) : name{n} { value.uw = v; }
      tag_item_t(uint32_t n, uint32_t v) : name{n} { value.ul = v; }
      tag_item_t(uint32_t n, int8_t v) : name{n} { value.b = v; }
      tag_item_t(uint32_t n, int16_t v) : name{n} { value.w = v; }
      tag_item_t(uint32_t n, int32_t v) : name{n} { value.l = v; }
      tag_item_t(uint32_t n, const char* v) : name{n} { value.cstr = v; }
      tag_item_t(uint32_t n, char* v) : name{n} { value.str = v; }
      tag_item_t(uint32_t n, ptr_t v) : name{n} { value.ptr = v; }

      bool is_end() const {
          return name == 0UL;
      }

    };

    static_assert(sizeof(tag_item_t) == 8, "pod_variant_t was expected to be 8 bytes in size.");


}