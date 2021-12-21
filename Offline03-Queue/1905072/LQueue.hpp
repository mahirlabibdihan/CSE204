#ifndef __L_QUEUE__
#define __L_QUEUE__
#include "Queue.hpp"
#include "Link.hpp"
// Linked queue implementation
template <typename E>
class LQueue : public Queue<E>
{
private:
    Link<E> *front; // Pointer to front queue node
    Link<E> *rear;  // Pointer to rear queue node
    int size;       // Number of elements in queue
public:
    LQueue(int sz = 0) // Constructor
    {
        front = rear = new Link<E>();
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
    void enqueue(const E &it)
    { // Put element on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue()
    { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element;  // Store dequeued value
        Link<E> *ltemp = front->next; // Hold dequeued link
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