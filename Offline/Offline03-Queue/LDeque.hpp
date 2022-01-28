#ifndef __L_QUEUE__
#define __L_QUEUE__
#include "Deque.hpp"
#include "DLink.hpp"
// Linked queue implementation
template <typename E>
class LDeque : public Deque<E>
{
    Link<E> *frontLink; // Pointer to front queue node
    Link<E> *backLink;  // Pointer to rear queue node
    int size;           // Number of elements in queue
    void init()
    { // Intialization helper method
        size = 0;
        frontLink = new DLink<E>();
        backLink = new DLink<E>();
        frontLink->next = backLink;
        ((DLink<E> *)backLink)->prev = frontLink;
    }
    void removeAll()
    { // Return link nodes to free store
        while (frontLink != NULL)
        {
            Link<E> *temp = frontLink;
            frontLink = frontLink->next;
            delete temp;
        }
    }

public:
    LDeque(int sz = 0) // Constructor
    {
        init();
    }
    ~LDeque()
    {
        removeAll();
    }
    // Destructor
    void clear()
    {
        removeAll();
        init();
    }
    void push_back(const E &it)
    {
        ((DLink<E> *)backLink)->prev =
            ((DLink<E> *)backLink)->prev->next =
                new DLink<E>(it, ((DLink<E> *)backLink)->prev, backLink);
        size++;
    }
    void push_front(const E &it)
    {
        frontLink->next =
            ((DLink<E> *)frontLink->next)->prev =
                new DLink<E>(it, frontLink, frontLink->next);
        size++;
    }
    E pop_front()
    {
        // Remove element from front
        Assert(size != 0, "Queue is empty");
        Link<E> *ltemp = frontLink->next; // Hold dequeued link
        E it = ltemp->element;            // Store dequeued value
        ((DLink<E> *)ltemp->next)->prev = frontLink;
        frontLink->next = ltemp->next; // Advance front
        delete ltemp;                  // Delete link
        size--;
        return it; // Return element value
    }
    E pop_back()
    {
        // Remove element from front
        Assert(size != 0, "Queue is empty");
        Link<E> *ltemp = ((DLink<E> *)backLink)->prev; // Hold dequeued link
        E it = ltemp->element;                         // Store dequeued value
        ((DLink<E> *)ltemp)->prev->next = backLink;
        ((DLink<E> *)backLink)->prev = ((DLink<E> *)ltemp)->prev; // Advance front
        delete ltemp;                                             // Delete link
        size--;
        return it; // Return element value
    }
    const E &front() const
    {
        return frontLink->next->element;
    }
    const E &back() const
    {
        return ((DLink<E> *)backLink)->prev->element;
    }
    int length() const { return size; }
};
#endif