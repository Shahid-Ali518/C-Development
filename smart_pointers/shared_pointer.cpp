#include <iostream>

template<typename T>
class SharedPointer
{
private:
    T* ptr;
    size_t* count;

    void release()
    {
        if(count)
        {
            --(*count);

            if(*count==0)
            {
                delete ptr;
                delete count;
            }
        }
    }

public:

    explicit SharedPointer(T* p=nullptr)
    {
        ptr=p;

        if(p)
            count=new size_t(1);
        else
            count=nullptr;
    }

    ~SharedPointer()
    {
        release();
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    SharedPointer(const SharedPointer& other)
    {
        ptr=other.ptr;
        count=other.count;

        if(count)
            ++(*count);
    }

    SharedPointer& operator=(const SharedPointer& other)
    {
        if(this!=&other)
        {
            release();

            ptr=other.ptr;
            count=other.count;

            if(count)
                ++(*count);
        }

        return *this;
    }

    SharedPointer(SharedPointer&& other) noexcept
    {
        ptr=other.ptr;
        count=other.count;

        other.ptr=nullptr;
        other.count=nullptr;
    }

    SharedPointer& operator=(SharedPointer&& other) noexcept
    {
        if(this!=&other)
        {
            release();

            ptr=other.ptr;
            count=other.count;

            other.ptr=nullptr;
            other.count=nullptr;
        }

        return *this;
    }

    size_t use_count() const
    {
        return count ? *count : 0;
    }
};

template<typename T, typename... Args>
SharedPointer<T> makeShared(Args&&... args)
{
    return SharedPointer<T>(new T(std::forward<Args>(args)...));
}

int main()
{
    SharedPointer<int> sp1 = makeShared<int>(42);
    std::cout << "Value: " << *sp1 << ", Use count: " << sp1.use_count() << std::endl;

    SharedPointer<int> sp2 = sp1; // Copy constructor
    std::cout << "Value: " << *sp2 << ", Use count: " << sp2.use_count() << std::endl;

    SharedPointer<int> sp3;
    sp3 = sp1; // Copy assignment
    std::cout << "Value: " << *sp3 << ", Use count: " << sp3.use_count() << std::endl;

    return 0;
}