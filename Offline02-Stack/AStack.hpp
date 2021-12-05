#ifndef __A_STACK__
#define __A_STACK__
#include <iostream>
#include "Stack.hpp"
using namespace std;
// Array-based stack implementation
template <typename E>
class AStack : public Stack<E>
{
private:
    static const int defaultSize = 10;
    int maxSize;  // Maximum size of stack
    int top;      // Index for top element
    E *listArray; // Array holding stack elements
    int dir;
    int chunk;
    void realloc(int size)
    {
        // Reallocating memory to store more elements
        E *temp = new E[size];

        for (int i = 0; i < maxSize; i++)
        {
            if (dir == 1)
                temp[i] = listArray[i];
            else
                temp[maxSize + i] = listArray[i];
        }
        maxSize = size;
        delete[] listArray;
        listArray = temp;
    }

public:
    AStack(int size = defaultSize) // Constructor
    {
        chunk = maxSize = size;
        dir = 1;
        top = 0;
        listArray = new E[size];
    }
    AStack(E *arr, int direction, int size = defaultSize) // Constructor
    {
        chunk = maxSize = size;
        dir = direction;
        top = (dir == 1 ? 0 : maxSize - 1);
        listArray = arr;
    }
    ~AStack() { delete[] listArray; } // Destructor
    void clear()
    {
        top = (dir == 1 ? 0 : maxSize - 1);
    } // Reinitialize
    void push(const E &it)
    { // Put "it" on stack
        if (length() == maxSize)
        {
            realloc(maxSize + chunk);
        }
        listArray[top] = it;
        top += dir;
    }
    E pop()
    { // Pop top element
        Assert(length() > 0, "Stack is empty");
        return listArray[top -= dir];
    }
    const E &topValue() const
    { // Return top element
        Assert(length() > 0, "Stack is empty");
        return listArray[top - dir];
    }
    int length() const // Return length
    {
        return (dir == 1 ? top : maxSize - 1 - top);
    }
    void setDirection(int direction)
    {
        Assert(length() == 0, "Stack is not Empty");
        dir = direction;
        top = (dir == 1 ? 0 : maxSize - 1);
    }
};
#endif