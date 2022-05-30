#pragma once

#include <type_traits>
#include <utility>

template<class T>
using CloneResultType = decltype(std::declval<T&>().clone());

template<class T>
class ClonePtr {
    static_assert(std::is_convertible_v<CloneResultType<T>, T*>, "T must provide a clone() method");

public:
    ClonePtr(std::nullptr_t) {}
    explicit ClonePtr() = default;
    explicit ClonePtr(T *p) : p_(p) {}  // take ownership
    ~ClonePtr() { delete p_; }          // discharge our responsibility

    T *operator->() const noexcept { return p_; }
    T& operator*() const noexcept { return *p_; }
    T *get() const noexcept { return p_; }
    explicit operator bool() const noexcept { return p_ != nullptr; }
    friend bool operator==(const ClonePtr& a, const ClonePtr& b) { return a.p_ == b.p_; }
    friend bool operator!=(const ClonePtr& a, const ClonePtr& b) { return a.p_ != b.p_; }

    template<class U> friend class ClonePtr;

    template<class U, class = std::enable_if_t<std::is_convertible_v<CloneResultType<U>, T*>>>
    ClonePtr(const ClonePtr<U>& rhs) {
        if (rhs != nullptr) {
            p_ = static_cast<U*>(rhs->clone());
        }
    }

    template<class U, class = std::enable_if_t<std::is_convertible_v<CloneResultType<U>, T*>>>
    ClonePtr(ClonePtr<U>&& rhs) {
        p_ = std::exchange(rhs.p_, nullptr);
    }

    ClonePtr(const ClonePtr& rhs) {
        if (rhs != nullptr) {
            p_ = rhs->clone();
        }
    }

    ClonePtr& operator=(const ClonePtr& rhs) {
        ClonePtr copy = rhs;
        copy.swap(*this);
        return *this;
    }

    ClonePtr(ClonePtr&& rhs) noexcept {
        p_ = std::exchange(rhs.p_, nullptr);
    }

    ClonePtr& operator=(ClonePtr&& rhs) noexcept {
        ClonePtr copy = std::move(rhs);
        copy.swap(*this);
        return *this;
    }

    void swap(ClonePtr& rhs) noexcept {
        std::swap(p_, rhs.p_);
    }

    friend void swap(ClonePtr& a, ClonePtr& b) noexcept {
        a.swap(b);
    }

private:
    T* p_ = nullptr;
};


template<class T, class... Args>
ClonePtr<T> make_clone(Args&&... args) {
    return ClonePtr<T>(new T(std::forward<Args>(args)...));
}

// Pro tip: Instead of `std::forward<Args>(args)...`,
// some people use `static_cast<Args&&>(args)...`.
// It achieves the same effect, without instantiating
// the library function template `std::forward`.
// Therefore it is "cheaper" for the compiler.
// I'm not saying you should use `static_cast<Args&&>`,
// but you should at least understand its purpose
// when you see it used elsewhere.


// Here's one (ill-advised) solution to the extra test cases.
// The C++17 library provides extra signatures like this
// in a very few places (optional, variant, any).
// This "solution" works well for our IntSet test case,
// but observe how it would fail for StringSet
// or even HeterogeneousPair.

template<class T, class U, class... Args>
ClonePtr<T> make_clone(std::initializer_list<U> il, Args&&... args) {
    return ClonePtr<T>(new T(il, std::forward<Args>(args)...));
}
