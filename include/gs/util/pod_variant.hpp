#pragma once

#include <gs/util/types.hpp>

namespace gs::util {

    enum class pod_variant_kind_t {
        None,
        UnsignedByte,
        UnsignedWord,
        UnsignedLong,
        SignedByte,
        SignedWord,
        SignedLong,
        ConstString,
        String,
        Pointer,
    };

    union pod_variant_u {
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

    static_assert(sizeof(pod_variant_u) == 4, "pod_variant_u was expected to be 4 bytes in size.");

    struct pod_variant_t {
      gs::util::pod_variant_kind_t kind;
      gs::util::pod_variant_u value;

      pod_variant_t() : kind{pod_variant_kind_t::None}, value{} {}
      pod_variant_t(uint8_t v) : kind{pod_variant_kind_t::UnsignedByte} { value.ub = v; }
      pod_variant_t(uint16_t v) : kind{pod_variant_kind_t::UnsignedWord} { value.uw = v; }
      pod_variant_t(uint32_t v) : kind{pod_variant_kind_t::UnsignedLong} { value.ul = v; }
      pod_variant_t(int8_t v) : kind{pod_variant_kind_t::SignedByte} { value.b = v; }
      pod_variant_t(int16_t v) : kind{pod_variant_kind_t::SignedWord} { value.w = v; }
      pod_variant_t(int32_t v) : kind{pod_variant_kind_t::SignedLong} { value.l = v; }
      pod_variant_t(const char* v) : kind{pod_variant_kind_t::ConstString} { value.cstr = v; }
      pod_variant_t(char* v) : kind{pod_variant_kind_t::String} { value.str = v; }
      pod_variant_t(ptr_t v) : kind{pod_variant_kind_t::Pointer} { value.ptr = v; }

    };

    static_assert(sizeof(pod_variant_t) == 8, "pod_variant_t was expected to be 8 bytes in size.");

}