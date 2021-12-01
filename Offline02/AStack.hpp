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

public:
    AStack(int size = defaultSize) // Constructor
    {
        chunk = maxSize = size;
        top = 0;
        listArray = new E[size];
        dir = 1;
    }
    AStack(int *arr, int direction, int size = defaultSize) // Constructor
    {
        chunk = maxSize = size;
        if (dir == 1)
        {
            top = 0;
        }
        else
        {
            top = maxSize - 1;
        }
        listArray = arr;
        dir = direction;
    }
    ~AStack() { delete[] listArray; } // Destructor
    void clear()
    {
        if (dir == 1)
        {
            top = 0;
        }
        else
        {
            top = maxSize - 1;
        }
    } // Reinitialize
    void push(const E &it)
    { // Put "it" on stack
        if (length() == maxSize)
        {
            // Reallocating memory to store more elements
            E *temp = new E[maxSize + chunk];

            for (int i = 0; i < maxSize; i++)
            {
                if (dir == 1)
                    temp[i] = listArray[i];
                else
                    temp[maxSize + i] = listArray[i];
            }
            maxSize += chunk;
            delete[] listArray;
            listArray = temp;
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
    int length() const
    {
        if (dir == 1)
            return top;
        else
            return maxSize - top - 1;
    } // Return length
    void setDirection(int direction)
    {
        Assert(length() == 0, "Stack is not Empty");
        dir = direction;
        if (dir == 1)
        {
            top = 0;
        }
        else
        {
            top = maxSize - 1;
        }
    }
};