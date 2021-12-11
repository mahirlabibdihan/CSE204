#ifndef __L_QUEUE__
#define __L_QUEUE__
#include "Queue.hpp"
#include "Link.hpp"
// Linked queue implementation
template <typename T>
class LQueue : public Queue<T>
{
private:
    Link<T> *front; // Pointer to front queue node
    Link<T> *rear;  // Pointer to rear queue node
    int size;       // Number of elements in queue
public:
    LQueue(int sz = 0) // Constructor
    {
        front = rear = new Link<T>();
        size = 0;
    }
    ~LQueue()
    {
        clear();
        delete front;
    } // Destructor
    void clear()
    { // Clear queue
        while (front->next != NULL)
        { // Delete each link node
            rear = front->next;
            delete front;
            front = rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(const T &it)
    { // Put element on rear
        rear->next = new Link<T>(it, NULL);
        rear = rear->next;
        size++;
    }
    T dequeue()
    { // Remove element from front
        Assert(size != 0, "Queue is empty");
        T it = front->next->element;  // Store dequeued value
        Link<T> *ltemp = front->next; // Hold dequeued link
        front->next = ltemp->next;    // Advance front
        if (rear == ltemp)
            rear = front; // Dequeue last element
        delete ltemp;     // Delete link
        size--;
        return it; // Return element value
    }
    int length() const { return size; }
    const T &frontValue() const
    { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
    }
    const T &rearValue() const
    { // Get front value
        Assert(length() != 0, "Queue is empty");
        return rear->element;
    }
    const T leaveQueue()
    {
        Assert(length() != 0, "Queue is empty");
        Link<T> *tmp = front;
        while (tmp->next != rear)
        {
            tmp = tmp->next;
        }
        T top = rear->element;
        tmp->next = NULL;
        delete rear;
        rear = tmp;
        size--;
        return top;
    }
    /*const T leaveQueue()
    {
        Assert(length() != 0, "Queue is empty");
        T tmp = dequeue();
        for (int i = 0; i < length(); i++)
        {
            enqueue(tmp);
            tmp = dequeue();
        }
        return tmp;
    }*/
};
#endif