#ifndef __A_DEQUE__
#define __A_DEQUE__
#include "Deque.hpp"

// Array-based Deque implementation
template <typename E>
class ADeque : public Deque<E>
{
private:
    static const int defaultSize = 10;
    int maxSize;  // Maximum size of Deque
    int frontIdx; // Index of front element
    int backIdx;  // Index of back element
    E *listArray; // Array holding Deque elements
    void expand()
    {
        // Reallocating memory to store more elements
        E *tmp = new E[2 * maxSize - 1];

        for (int i = 1; i < maxSize; i++)
        {
            tmp[i] = listArray[(frontIdx + i - 1) % maxSize];
        }
        frontIdx = 1;
        backIdx = maxSize - 1;
        maxSize = 2 * maxSize - 1;
        delete[] listArray;
        listArray = tmp;
    }

public:
    ADeque(int size = defaultSize)
    { // Constructor
        // Make list array one position larger for empty slot
        maxSize = size + 1;
        backIdx = 0;
        frontIdx = 1;
        listArray = new E[maxSize];
    }
    ~ADeque() { delete[] listArray; } // Destructor
    void clear()
    {
        // Reinitialize
        delete[] listArray;
        backIdx = 0;
        frontIdx = 1;
        listArray = new E[maxSize];
    }
    void push_back(const E &it)
    { // Put "it" in Deque
        if (length() == maxSize - 1)
        {
            expand();
        }
        backIdx = (backIdx + 1) % maxSize; // Circular increment
        listArray[backIdx] = it;
    }
    void push_front(const E &it)
    { // Put "it" in Deque
        if (length() == maxSize - 1)
        {
            expand();
        }
        frontIdx = (frontIdx - 1) % maxSize; // Circular increment
        listArray[frontIdx] = it;
    }
    E pop_front()
    { // Take element out
        Assert(length() != 0, "Deque is empty");
        E it = listArray[frontIdx];
        frontIdx = (frontIdx + 1) % maxSize; // Circular increment
        return it;
    }
    E pop_back()
    { // Take element out
        Assert(length() != 0, "Queue is empty");
        E it = listArray[backIdx];
        backIdx = (backIdx - 1 + maxSize) % maxSize; // Circular decrement
        return it;
    }
    int length() const // Return length
    {
        return ((backIdx + maxSize) - frontIdx + 1) % maxSize;
    }
    const E &front() const
    { // Get front value
        Assert(length() != 0, "Deque is empty");
        return listArray[frontIdx];
    }
    const E &back() const
    { // Get back value
        Assert(length() != 0, "Deque is empty");
        return listArray[backIdx];
    }
};
#endif