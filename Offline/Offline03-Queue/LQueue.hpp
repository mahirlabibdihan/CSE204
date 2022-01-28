#ifndef __L_QUEUE__
#define __L_QUEUE__
#include "Queue.hpp"
#include "SLink.hpp"
// Linked queue implementation
template <typename E>
class LQueue : public Queue<E>
{
private:
    Link<E> *front; // Pointer to front queue node
    Link<E> *rear;  // Pointer to rear queue node
    int size;       // Number of elements in queue
    void init()
    {
        front = rear = new SLink<E>();
        size = 0;
    }
    void removeAll()
    {
        while (front != NULL)
        { // Delete each link node
            rear = front->next;
            delete front;
            front = rear;
        }
    }

public:
    LQueue(int sz = 0) // Constructor
    {
        init();
    }
    ~LQueue()
    {
        removeAll();
    } // Destructor
    void clear()
    { // Clear queue
        removeAll();
        init();
    }
    void enqueue(const E &it)
    { // Put element on rear
        rear->next = new SLink<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue()
    { // Remove element from front
        Assert(size != 0, "Queue is empty");
        Link<E> *ltemp = front->next; // Hold dequeued link
        E it = ltemp->element;        // Store dequeued value
        front->next = ltemp->next;    // Advance front
        if (rear == ltemp)
            rear = front; // Dequeue last element
        delete ltemp;     // Delete link
        size--;
        return it; // Return element value
    }
    int length() const { return size; }
    const E &frontValue() const
    { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
    }
    const E &rearValue() const
    { // Get front value
        Assert(length() != 0, "Queue is empty");
        return rear->element;
    }
    const E leaveQueue()
    {
        Assert(length() != 0, "Queue is empty");
        Link<E> *tmp = front;
        while (tmp->next != rear)
        {
            tmp = tmp->next;
        }
        E top = rear->element;
        tmp->next = NULL;
        delete rear;
        rear = tmp;
        size--;
        return top;
    }
    /*const E leaveQueue()
    {
        Assert(length() != 0, "Queue is empty");
        E tmp = dequeue();
        for (int i = 0; i < length(); i++)
        {
            enqueue(tmp);
            tmp = dequeue();
        }
        return tmp;
    }*/
};
#endif