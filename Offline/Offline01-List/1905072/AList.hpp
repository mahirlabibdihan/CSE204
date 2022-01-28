#ifndef __A_LIST__
#define __A_LIST__
#include <iostream>
#include "List.hpp"
using namespace std;

// Array list implementation
template <typename E>
class AList : public List<E>
{
private:
    static const int defaultSize = 10;
    int chunk;
    int maxSize;
    int listSize;
    int curr;
    E *listArray;

public:
    AList(int maxSize = defaultSize)
    { // Constructor
        this->maxSize = maxSize;
        chunk = maxSize;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    AList(int *arr, int listSize, int maxSize = defaultSize)
    { // Constructor
        this->maxSize = maxSize;
        chunk = maxSize;
        this->listSize = listSize;
        curr = 0;
        listArray = new E[maxSize];
        for (int i = 0; i < listSize; i++)
        {
            listArray[i] = arr[i];
        }
    }
    ~AList()
    {
        delete[] listArray;
    }
    void clear()
    {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[defaultSize];
    }
    void insert(const E &it)
    { // Insert "it" at current position
        if (listSize < maxSize)
        {
            // Reallocating memory to store double elements
            E *temp = new E[2 * maxSize];
            for (int i = 0; i < maxSize; i++)
            {
                temp[i] = listArray[i];
            }
            maxSize += chunk;
            delete[] listArray;
            listArray = temp;
        }
        for (int i = listSize; i > curr; i--) // Shift elements up
        {
            listArray[i] = listArray[i - 1]; // to make room
        }

        listArray[curr] = it;
        listSize++; // Increment list size
    }
    void append(const E &it)
    { // Append "it"
        if (listSize < maxSize)
        {
            // Reallocating memory to store double elements
            E *temp = new E[maxSize + chunk];
            for (int i = 0; i < maxSize; i++)
            {
                temp[i] = listArray[i];
            }
            maxSize += chunk;
            delete[] listArray;
            listArray = temp;
        }
        listArray[listSize++] = it;
    }

    E remove()
    { // Remove and return the current element.
        if ((curr < 0) || (curr >= listSize))
        {
            cout << "No element" << endl;
            exit(-1);
        }
        E it = listArray[curr];
        for (int i = curr; i < listSize - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        if (curr == listSize)
        {
            if (curr != 0)
            {
                curr--;
            }
        }
        return it;
    }
    void moveToStart()
    {
        curr = 0;
    }
    void moveToEnd()
    {
        curr = listSize - 1;
    }
    void prev()
    {
        if (curr == 0)
        {
            cout << "Already at first position" << endl;
            exit(-1);
        }
        curr--;
    }
    void next()
    {
        if (curr == listSize)
        {
            cout << "Already at last position" << endl;
            exit(-1);
        }
        curr++;
    }
    int length() const
    {
        return listSize;
    }
    int currPos() const
    { // Return current position
        return curr;
    }
    void moveToPos(int pos)
    { // Set current list position to "pos"
        if ((pos < 0) || (pos >= listSize))
        {
            cout << "Pos out of range" << endl;
            exit(-1);
        }
        curr = pos;
    }
    const E &getValue() const
    { // Return current element
        if ((curr < 0) || (curr >= listSize))
        {
            cout << "No current element" << endl;
            exit(-1);
        }
        return listArray[curr];
    }
    int search(const E &item) const
    { // search for item in the list
        for (int i = 0; i < listSize; i++)
        {
            if (listArray[i] == item)
            {
                return i;
            }
        }
        return -1;
    }
};
#endif