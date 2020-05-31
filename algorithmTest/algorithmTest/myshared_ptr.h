#pragma once


#include <utility>  // std::swap

class shared_count {
public:
    shared_count() noexcept
        : count_(1) {}

    void add_count() noexcept
    {
        ++count_;
    }

    long reduce_count() noexcept
    {
        return --count_;
    }

    long get_count() const noexcept
    {
        return count_;
    }

private:
    long count_;
};

template <typename T>
class myshared_ptr {
public:
    template <typename U>
    friend class myshared_ptr;

    explicit myshared_ptr(T* ptr = nullptr)
        : ptr_(ptr)
    {
        if (ptr) {
            shared_count_ =
                new shared_count();
        }
    }
    ~myshared_ptr()
    {
        if (ptr_ &&
            !shared_count_
            ->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }

    myshared_ptr(const myshared_ptr& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_>add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    myshared_ptr(const myshared_ptr<U>& other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    myshared_ptr(myshared_ptr<U>&& other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    template <typename U>
    myshared_ptr(const myshared_ptr<U>& other,
        T* ptr) noexcept
    {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    myshared_ptr&
        operator=(myshared_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    T* get() const noexcept
    {
        return ptr_;
    }
    long use_count() const noexcept
    {
        if (ptr_) {
            return shared_count_
                ->get_count();
        }
        else {
            return 0;
        }
    }
    void swap(myshared_ptr& rhs) noexcept
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_,
            rhs.shared_count_);
    }

    T& operator*() const noexcept
    {
        return *ptr_;
    }
    T* operator->() const noexcept
    {
        return ptr_;
    }
    operator bool() const noexcept
    {
        return ptr_;
    }

private:
    T* ptr_;
    shared_count* shared_count_;
};

template <typename T>
void swap(myshared_ptr<T>& lhs,
    myshared_ptr<T>& rhs) noexcept
{
    lhs.swap(rhs);
}

template <typename T, typename U>
myshared_ptr<T> static_pointer_cast(
    const myshared_ptr<U>& other) noexcept
{
    T* ptr = static_cast<T*>(other.get());
    return myshared_ptr<T>(other, ptr);
}

template <typename T, typename U>
myshared_ptr<T> reinterpret_pointer_cast(
    const myshared_ptr<U>& other) noexcept
{
    T* ptr = reinterpret_cast<T*>(other.get());
    return myshared_ptr<T>(other, ptr);
}

template <typename T, typename U>
myshared_ptr<T> const_pointer_cast(
    const myshared_ptr<U>& other) noexcept
{
    T* ptr = const_cast<T*>(other.get());
    return myshared_ptr<T>(other, ptr);
}

template <typename T, typename U>
myshared_ptr<T> dynamic_pointer_cast(
    const myshared_ptr<U>& other) noexcept
{
    T* ptr = dynamic_cast<T*>(other.get());
    return myshared_ptr<T>(other, ptr);
}