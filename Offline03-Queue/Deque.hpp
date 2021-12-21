#ifndef __DEQUE__
#define __DEQUE__
#include <iostream>
#include <cstdlib>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// Abstract Deque class
template <typename E>
class Deque
{
private:
    void operator=(const Deque &) {} // Protect assignment
    Deque(const Deque &) {}          // Protect copy constructor
public:
    Deque() {}          // Default
    virtual ~Deque() {} // Base destructor
    // Reinitialize the Deque. The user is responsible for
    // reclaiming the storage used by the Deque elements.
    virtual void clear() = 0;
    // Place an element at the rear of the Deque.
    // it: The element being enDequed.
    virtual void push_front(const E &it) = 0;
    virtual void push_back(const E &it) = 0;

    // Remove and return element at the front of the Deque.
    // Return: The element at the front of the Deque.
    virtual E pop_front() = 0;
    virtual E pop_back() = 0;
    // Return: The number of elements in the Deque.
    virtual int length() const = 0;
    // Return: A copy of the front element.
    virtual const E &front() const = 0;
    // Return: A copy of the front element.
    virtual const E &back() const = 0;
};
#endif