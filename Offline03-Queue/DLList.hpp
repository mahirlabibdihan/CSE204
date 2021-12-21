#ifndef __D_L_LIST__
#define __D_L_LIST__
#include <iostream>
#include "LList.hpp"
#include "DLink.hpp"
using namespace std;

// Doubly Linked list implementation
template <typename E>
class DLList : public LList<E>
{
private:
    void init()
    { // Intialization helper method
        LList<E>::init();
        this->curr = this->head = new DLink<E>();
        this->tail = new DLink<E>();
        this->head->next = this->tail;
        ((DLink<E> *)this->tail)->prev = this->head;
    }

public:
    DLList(int maxSize = 0)
    {
        init();
    }
    DLList(int *arr, int listSize, int maxSize = 0)
    {
        init();
        // Copying elements form array to list
        for (int i = 0; i < listSize; i++)
        {
            this->append(arr[i]);
        }
    }
    virtual ~DLList()
    {
    }
    void clear()
    {
        LList<E>::removeall();
        init();
    }
    // Insert "it" at current position
    void insert(const E &it)
    {
        this->curr->next =
            ((DLink<E> *)this->curr->next)->prev =
                new DLink<E>(it, this->curr, this->curr->next);
        this->listSize++;
    }
    void append(const E &it)
    {
        ((DLink<E> *)this->tail)->prev =
            ((DLink<E> *)this->tail)->prev->next =
                new DLink<E>(it, ((DLink<E> *)this->tail)->prev, this->tail);
        this->listSize++;
    }
    // Remove and return current element
    E remove()
    {
        Assert(this->curr->next != this->tail, "Empty List"); // Nothing to remove
        E it = this->curr->next->element;                     // Remember value
        Link<E> *ltemp = this->curr->next;                    // Remember link node
        ((DLink<E> *)this->curr->next->next)->prev = this->curr;
        this->curr->next = this->curr->next->next; // Remove from list
        delete ltemp;                              // Reclaim space
        this->listSize--;                          // Decrement cnt
        if (this->curr->next == this->tail)        // If the last element is deleted, this->curr pointer will step back
        {
            if (this->curr != this->head) // Until it was also the first element. because if first element got deleted we can't step back
            {
                this->prev();
            }
        }
        return it;
    }
    // Move fence one step left; no change if left is empty
    void prev()
    {
        if (this->curr == this->head) // Can’t back up from list this->head
        {
            cout << "Already at first position" << endl;
            return; // No previous element
        }
        this->curr = ((DLink<E> *)this->curr)->prev;
    }
    void moveToEnd() // Place curr at list end
    {
        this->curr = ((DLink<E> *)this->tail)->prev;
        if (this->curr != this->head)
        {
            this->prev();
        }
    }
};
#endif