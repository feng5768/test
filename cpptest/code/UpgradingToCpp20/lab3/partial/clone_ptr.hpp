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


// YOUR CODE GOES HERE --
// you should rewrite the "make_clone" function.

template<class T>
ClonePtr<T> make_clone(int arg) {
    return ClonePtr<T>(new T(arg));
}
