#include <iostream>
#include <memory>


int main ()
{
    std::unique_ptr<int> ptr = std::make_unique<int>(420);
    std::cout << *ptr << std::endl;

    std::unique_ptr<int> ptr2 = std::make_unique<int>(100); // Transfer ownership to ptr2
    // unique_ptr methods 

    ptr.get(); // returns the raw pointer
    
    ptr.get_deleter(); // returns the deleter associated with the unique_ptr
    
    ptr.swap(ptr2); // swaps the managed objects of two unique_ptr instances

    std::cout << "Value: " << *ptr2 << std::endl; // This will print 42 because ptr2 now owns the object.
    
    ptr.release(); // releases ownership of the managed object and returns the pointer to it. After this call, the unique_ptr becomes empty.
    ptr.reset(); // destroys the managed object and sets the unique_ptr to nullptr. If a

    // std:: cout << "Value: " << *ptr << std::endl; // This will cause a runtime error because ptr is now nullptr.
    

    std::cout << "Shared Pointer Example ======================" << std::endl;

    std::shared_ptr<int> sptr1 = std::make_shared<int>(42);

    std::shared_ptr<int> sptr2 = sptr1; // Copying shared_ptr increases the reference count

    std::cout << "Value: " << *sptr1 << ", Use count: " << sptr1.use_count() << std::endl;
    std::cout << "Value: " << *sptr2 << ", Use count: " << sptr2.use_count() << std::endl;

    // methods of shared_ptr
    std::cout << "sptr1.get(): " << sptr1.get() << std::endl; // returns the raw pointer

    std::cout << sptr1.unique() << std::endl; // returns true if the shared_ptr is the only owner of the managed object

    std::cout << "sptr1.use_count(): " << sptr1.use_count() << std::endl; // returns the number of shared_ptr instances managing the same object

    std::cout << "sptr1.reset(): " << std::endl; // releases ownership of the managed object and decreases the reference count. If the reference count becomes zero, the managed object is deleted.
    sptr1.reset();

    std::cout << "sptr1.owner_before(sptr2): " << sptr1.owner_before(sptr2) << std::endl; // returns true if sptr1 is ordered before sptr2 in the ownership order
    
    sptr1.swap(sptr2); // swaps the managed objects of two shared_ptr instances

    std::cout << "Weak Pointer Example ======================" << std::endl;

    std::shared_ptr<int> sharedPtr = std::make_shared<int>(100);
    std::weak_ptr<int> weakPtr = sharedPtr; // Create a weak_ptr from a shared_ptr

    if (auto lockedPtr = weakPtr.lock()) { // Attempt to lock the weak_ptr to get a shared_ptr
        std::cout << "Value from weak_ptr: " << *lockedPtr << std::endl;
    } else {
        std::cout << "The object has been deleted." << std::endl;
    }

    // methods of weak_ptr
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl; // returns true if the managed object has already been deleted

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl; // returns the number of shared_ptr instances managing the same object

    std::cout << "weakPtr.lock(): " << std::endl; // returns a shared_ptr that shares ownership of the managed object if it still exists, otherwise returns an empty shared_ptr
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Value from weak_ptr: " << *lockedPtr << std::endl;
    } else {
        std::cout << "The object has been deleted." << std::endl;
    }

    std::cout << "weakPtr.reset(): " << std::endl; // releases the ownership of the managed object and decreases the reference count. If the reference count becomes zero, the managed object is deleted.
    weakPtr.reset();

    std::cout << weakPtr.expired() << std::endl; // returns true if the managed object has already been deleted

    std::cout << *sharedPtr << std::endl; // prints the address of the managed object or nullptr if it has been deleted

    //weakPtr.swap(sharedPtr); // swaps the managed objects of two weak_ptr instances

    

    return 0;
}
