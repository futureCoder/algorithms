#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<typename T>
class Singleton
{
public:
    static T& Instance()
    {
        if (nullptr == value_)
        {
            value_ = new T();
        }
        return *value_;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
private:
    Singleton() = default;
    ~Singleton() = default;

    static void Init()
    {
        value_ = new T();
    }

    static void Destroy()
    {
        delete value_;
    }

private:
    static T* value_;
};

template<typename T>
T* Singleton<T>::value_ = nullptr;

#endif // !__SINGLETON_H__