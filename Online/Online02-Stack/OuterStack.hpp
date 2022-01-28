#include "AStack.hpp"
template <typename E>
class OuterStack:public Stack<E>
{
    int sCount;
    static const int defaultSize = 10;
    int maxSize;
    AStack<int> **arr;
public:
    OuterStack(int size = defaultSize)
    {
        maxSize = size;
        arr = new AStack<int>*[100];
        arr[0] = new AStack<int>(maxSize);
        sCount = 1;
    }
    ~OuterStack()
    {
        for(int i=0; i<sCount; i++)
        {
            delete arr[i];
        }
        delete[] arr;
    } // Base destructor
    void clear()
    {
        for(int i=0; i<sCount; i++)
        {
            delete arr[i];
        }
        sCount = 0;
    }
    void push(const E &it)
    {
        if(sCount == 0)
        {
            arr[sCount++] = new AStack<int>(maxSize);
        }
        else if(arr[sCount-1]->length() == maxSize)
        {
            arr[sCount++] = new AStack<int>(maxSize);
        }
        arr[sCount-1]->push(it);
    }
    E pop()
    {
        Assert(sCount > 0, "Stack is empty");
        E tmp = arr[sCount-1]->pop();   // Pop top element
        if(arr[sCount-1]->length() == 0)    // If  current stack is empty after pop
        {
            delete arr[sCount-1];   // Deallocate current stack memory
            sCount--;   // Decrease stack counts
        }
        return tmp; // Return poped element
    }
    int length() const
    {
        if(sCount == 0)
            return 0;
        return (sCount-1)*maxSize+arr[sCount-1]->length();
    }
    const E &topValue() const
    {
        return arr[sCount-1]->topValue();
    }
    void setDirection(int direction)
    {
        cout<<"Not Implemented yet"<<endl;
    }
};

