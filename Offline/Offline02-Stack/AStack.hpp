#ifndef __A_STACK__
#define __A_STACK__
#include <iostream>
#include "Stack.hpp"
using namespace std;
// Array-based stack implementation
template <typename T>
class AStack : public Stack<T>
{
private:
    static const int defaultSize = 10;
    int maxSize;  // Maximum size of stack
    int top;      // Index for top element
    T *listArray; // Array holding stack elements
    int dir;
    void expand()
    {
        // Reallocating memory to store more elements
        T *temp = new T[2 * maxSize];

        for (int i = 0; i < maxSize; i++)
        {
            if (dir == 1)
                temp[i] = listArray[i];
            else
                temp[maxSize + i] = listArray[i];
        }
        maxSize *= 2;
        delete[] listArray;
        listArray = temp;
    }

public:
    AStack(int size = defaultSize) // Constructor
    {
        maxSize = size;
        dir = 1;
        top = 0;
        listArray = new T[size];
    }
    AStack(T *arr, int direction, int size = defaultSize) // Constructor
    {
        maxSize = size;
        dir = direction;
        top = (dir == 1 ? 0 : maxSize - 1);
        listArray = arr;
    }
    ~AStack() { delete[] listArray; } // Destructor
    void clear()
    {
        top = (dir == 1 ? 0 : maxSize - 1);
    } // Reinitialize
    void push(const T &it)
    { // Put "it" on stack
        if (length() == maxSize)
        {
            expand();
        }
        listArray[top] = it;
        top += dir;
    }
    T pop()
    { // Pop top element
        Assert(length() > 0, "Stack is empty");
        return listArray[top -= dir];
    }
    const T &topValue() const
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
        if (length() != 0)
        {
            cout << "Stack is not Empty" << endl;
            return;
        }
        dir = direction;
        top = (dir == 1 ? 0 : maxSize - 1);
    }
};
#endif