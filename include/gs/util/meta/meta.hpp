#pragma once

#include <gs/util/pod.hpp>

namespace gs::util::meta {

        template<typename T>
        constexpr T max(T lhs, T rhs) {
            return lhs > rhs ? lhs : rhs;
        }

        template<typename T>
        constexpr T min(T lhs, T rhs) {
            return lhs > rhs ? lhs : rhs;
        }

        template<typename T0, typename T1>
        constexpr size_t max_size() {
            return max(sizeof(T0), sizeof(T1));
        }

        template<typename T0, typename T1, typename T2>
        constexpr size_t max_size() {
            return max(max(sizeof(T0), sizeof(T1)), sizeof(T2));
        }

        template<typename T0, typename T1, typename T2, typename T3>
        constexpr size_t max_size() {
            return max(max(sizeof(T0), sizeof(T1)), max(sizeof(T2), sizeof(T3)));
        }

        template<typename T0, typename T1>
        struct is_same_type_impl { static constexpr bool value = false; };

        template<typename T>
        struct is_same_type_impl<T,T> { static constexpr bool value = true; };

        template<typename TL, typename TR>
        constexpr bool is_same_type() {
            return is_same_type_impl<TL, TR>::value;
        }

        template<size_t I, typename T0, typename T1>
        size_t construct_into(void* data) {
            if constexpr (I==0) {
                new(data)T0();
                return 0;
            }
            else if constexpr(I==1) {
                new(data)T1();
                return 1;
            }
            else {
                static_assert("Not supported type");
                return 2;
            }
        }

        template<size_t I, typename T0, typename T1, typename T2>
        size_t construct_into(void* data) {
            if constexpr (I==0) {
                new(data)T0();
                return 0;
            }
            else if constexpr(I==1) {
                new(data)T1();
                return 1;
            }
            else if constexpr(I==2) {
                new(data)T2();
                return 2;
            }
            else {
                static_assert("Not supported type");
                return 3;
            }
        }

        template<size_t I, typename T0, typename T1, typename T2, typename T3>
        size_t construct_into(void* data) {
            if constexpr (I==0) {
                new(data)T0();
                return 0;
            }
            else if constexpr(I==1) {
                new(data)T1();
                return 1;
            }
            else if constexpr(I==2) {
                new(data)T2();
                return 2;
            }
            else if constexpr(I==3) {
                new(data)T2();
                return 3;
            }
            else {
                static_assert("Not supported type");
                return 4;
            }
        }

        template<typename T, typename T0, typename T1>
        void construct_into(void* data) {
            if constexpr(is_same_type<T, T0>()) {
                new(data)T0();
            }
            else if constexpr(is_same_type<T, T1>()) {
                new(data)T1();
            }
            else {
                static_assert("Not supported type");
            }
        }

        template<typename T, typename T0, typename T1, typename T2>
        void construct_into(void* data) {
            if constexpr(is_same_type<T, T0>()) {
                new(data)T0();
            }
            else if constexpr(is_same_type<T, T1>()) {
                new(data)T1();
            }
            else if constexpr(is_same_type<T, T2>()) {
                new(data)T2();
            }
            else {
                static_assert("Not supported type");
            }
        }

        template<typename T, typename T0, typename T1, typename T2, typename T3>
        void construct_into(void* data) {
            if constexpr(is_same_type<T, T0>()) {
                new(data)T0();
            }
            else if constexpr(is_same_type<T, T1>()) {
                new(data)T1();
            }
            else if constexpr(is_same_type<T, T2>()) {
                new(data)T2();
            }
            else if constexpr(is_same_type<T, T3>()) {
                new(data)T3();
            }
            else {
                static_assert("Not supported type");
            }
        }

        template<typename T0, typename T1>
        bool delete_from(size_t index, void* data) {
            if (index == 0) {
                ((T0*)(data))->~T0();
                return true;
            }
            else if (index == 1) {
                ((T1*)(data))->~T1();
                return true;
            }
            else {
                return false;
            }
        }

        template<typename T0, typename T1, typename T2>
        bool delete_from(size_t index, void* data) {
            if (index == 0) {
                ((T0*)(data))->~T0();
                return true;
            }
            else if (index == 1) {
                ((T1*)(data))->~T1();
                return true;
            }
            else if (index == 2) {
                ((T2*)(data))->~T2();
                return true;
            }
            else {
                return false;
            }
        }

        template<typename T0, typename T1, typename T2, typename T3>
        bool delete_from(size_t index, void* data) {
            if (index == 0) {
                ((T0*)(data))->~T0();
                return true;
            }
            else if (index == 1) {
                ((T1*)(data))->~T1();
                return true;
            }
            else if (index == 2) {
                ((T2*)(data))->~T2();
                return true;
            }
            else if (index == 3) {
                ((T3*)(data))->~T3();
                return true;
            }
            else {
                return false;
            }
        }

    }

}