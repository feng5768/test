#pragma once

#include <algorithm>
#include <memory>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <utility>

template<class T, size_t N>
class fixed_vector {
    static_assert(std::is_trivial<T>::value, "T must be a trivial type");
    static_assert(N >= 1, "");
public:
    using value_type = T;
    using iterator = value_type *;
    using const_iterator = value_type const *;

    constexpr explicit fixed_vector(int n) { resize(n); }

    fixed_vector() = default;
    // this class follows the Rule of Zero

    template<std::input_iterator It, std::sentinel_for<It> Sent>
        requires std::convertible_to<std::iter_value_t<It>, T>
    constexpr explicit fixed_vector(It first, Sent last) {
        for ( ; first != last; ++first) {
            this->push_back(*first);
        }
    }

    constexpr fixed_vector(std::initializer_list<T> il) : fixed_vector(il.begin(), il.end()) {}

    // Here are some special member functions you shouldn't need to touch--

    constexpr size_t size() const noexcept { return size_; }
    constexpr size_t capacity() const noexcept { return N; }
    constexpr bool empty() const noexcept { return size_ == 0; }
    constexpr bool full() const noexcept { return size_ == N; }
    constexpr void throw_if_full() const { if (full()) throw std::out_of_range("fixed_vector initializer overflow"); }
    constexpr iterator begin() noexcept { return begin_addr(); }
    constexpr iterator end() noexcept { return begin_addr() + size(); }
    constexpr const_iterator begin() const noexcept { return begin_addr(); }
    constexpr const_iterator end() const noexcept { return begin_addr() + size(); }
    constexpr value_type& operator[](size_t i) { return begin_addr()[i]; }
    constexpr value_type const& operator[](size_t i) const { return begin_addr()[i]; }
    constexpr const value_type& front() const noexcept { return (*this)[0]; }
    constexpr const value_type& back() const noexcept { return (*this)[size() - 1]; }

    constexpr void push_back(const value_type& e) { throw_if_full(); begin_addr()[size_++] = e; }
    constexpr void pop_back() { begin_addr()[--size_] = T(); }
    constexpr void resize(size_t desired);

    friend constexpr bool operator==(const fixed_vector& a, const fixed_vector& b) {
        if (a.size() != b.size())
            return false;
        for (size_t i=0; i < a.size(); ++i)
            if (a[i] != b[i]) return false;
        return true;
    }

private:
    constexpr const T *begin_addr() const { return buf_; }
    constexpr T *begin_addr() { return buf_; }

    size_t size_ = 0;
    T buf_[N] {};
};

template<class T, size_t N>
constexpr void fixed_vector<T, N>::resize(size_t desired) {
    if (size_ < desired) {
        if (desired > capacity()) {
            throw std::out_of_range("Can't resize bigger than N elements!");
        }
        do {
            push_back(T());
        } while (size_ < desired);
    } else {
        while (size_ > desired) {
            pop_back();
        }
    }
}
