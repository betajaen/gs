#pragma once

#include <gs/util/pod.hpp>
#include <gs/util/variant.hpp>

namespace gs {

    enum class return_code_t : LONG;

    template<typename T>
    using rv_t = util::variant_t<return_code_t, T>;

    template<typename T>
    using optional_t = util::variant_t<T>;

}