#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class UniquePointer
{
private:
    T* ptr;

public:
    explicit UniquePointer(T* p = nullptr)
        : ptr(p)
    {
    }

    ~UniquePointer()
    {
        delete ptr;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePointer& operator=(UniquePointer&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

template<typename T, typename... Args>
UniquePointer<T> makeUnique(Args&&... args)
{
    return UniquePointer<T>(
        new T(std::forward<Args>(args)...)
    );
}

int main()
{
    auto ptr = makeUnique<int>(19);

    cout << *ptr << endl;
}