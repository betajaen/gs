#pragma once

#include <gs/util/meta/sizes.hpp>
#include <gs/util/meta/constructors.hpp>
#include <gs/util/meta/destructors.hpp>
#include <gs/util/meta/movers.hpp>
#include <gs/util/meta/selectors.hpp>

namespace gs::util {

    template<typename ...TTypes>
    struct variant_t {

        variant_t()  {
            // Set to no value.
            m_index = meta::construct_into<k_count, TTypes...>(m_data);
        }

        template<typename T>
        variant_t() {
            static_assert(meta::any_of<T, TTypes...>(), "Not valid type");
            m_index = meta::construct_into<T, TTypes...>(m_data);
        }

        template<typename T>
        variant_t(const T& value)
        {
            static_assert(meta::any_of<T, TTypes...>(), "Not valid type");
            m_index = meta::construct_into<T, TTypes...>(value, m_data);
        }

        template<typename T>
        variant_t(T&& value) {
            m_index = meta::move_into<T, TTypes...>(value, m_data);
        }

        variant_t(const variant_t& other) {
            if (other.is_none()) {
                m_index = k_count;
            }
            else {
                m_index = meta::copy_into<TTypes...>(m_data, other.m_data, other.m_index);
            }
        }

        variant_t(variant_t&& other) {
            if (other.is_none()) {
                m_index = k_count;
            }
            else {
                meta::move_into<TTypes...>(m_data, m_index, other.m_data, other.m_index, k_max_size);
            }
        }


        ~variant_t() {
            set_none();
        }

        variant_t& operator=(const variant_t& other) {
            set_none();

            if (other.has_value()) {
                m_index = meta::copy_into<TTypes...>(m_data, other.m_data, other.m_index);
            }
        }

        variant_t& operator=(variant_t&& other) {
            set_none();

            if (other.has_value()) {
                meta::move_into<TTypes...>(m_data, m_index, other.m_data, other.m_index, k_max_size);
            }
        }

        bool is_none() const {
            return m_index >= k_count;
        }

        bool has_value() const {
            return m_index < k_count;
        }

        template<typename T>
        bool is_value() const {
            return meta::index_of<T, TTypes...>() == m_index;
        }

        template<typename T>
        T* get() {
            static_assert(meta::any_of<T, TTypes...>(), "Not valid type");
            if (is_value<T>()) {
                return (T*) m_data;
            }
            else {
                return nullptr;
            }
        }

        template<typename T>
        void set(const T& value) {
            static_assert(meta::any_of<T, TTypes...>(), "Not valid type");
            meta::delete_from<TTypes...>(m_index, m_data);
            m_index = meta::construct_into<T, TTypes...>(value, m_data);
        }

        void set_none() {
            meta::delete_from<TTypes...>(m_index, m_data);
            m_index = k_count;
        }

    private:

        static constexpr size_t k_count = meta::count<TTypes...>();
        static constexpr size_t k_max_size = meta::size_of<TTypes...>();
        size_t m_index;
        uint8_t m_data[k_max_size];

    };

}