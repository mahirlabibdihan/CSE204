#ifndef __L_STACK__
#define __L_STACK__
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// Stack abtract class
#include <cstdlib>
template <typename E>
class Stack
{
private:
    void operator=(const Stack &) {} // Protect assignment
    Stack(const Stack &) {}          // Protect copy constructor
public:
    Stack() {}          // Default constructor
    virtual ~Stack() {} // Base destructor
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E &it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;
    // Return: The number of elements in the stack.
    virtual int length() const = 0;
    // Return: A copy of the top element.
    virtual const E &topValue() const = 0;
    virtual void setDirection(int direction) = 0;
};
#endif