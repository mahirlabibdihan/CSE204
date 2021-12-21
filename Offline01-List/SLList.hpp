#ifndef __S_L_LIST__
#define __S_L_LIST__
#include <iostream>
#include "SLink.hpp"
#include "LList.hpp"
using namespace std;
// Linked list implementation
template <typename E>
class SLList : public LList<E>
{
private:
    void init()
    { // Intialization helper method
        LList<E>::init();
        this->curr = this->tail = this->head = new SLink<E>;
    }

public:
    SLList(int maxSize = 0)
    {
        init();
    }
    SLList(int *arr, int listSize, int maxSize = 0)
    {
        init();
        // Copying elements form array to list
        for (int i = 0; i < listSize; i++)
        {
            this->append(arr[i]);
        }
    }
    ~SLList()
    {
        this->removeall();
    }
    void clear()
    {
        this->removeall();
        init();
    }
    void insert(const E &it)
    { // Insert "it" at current position
        this->curr->next = new SLink<E>(it, this->curr->next);
        this->listSize++;
    }
    void append(const E &it)
    { // Append "it" to list
        this->tail = this->tail->next = new SLink<E>(it);
        this->listSize++;
    }
    E remove()
    {
        // Remove and return current element
        Assert(this->curr->next != NULL, "Empty List"); // Next node of this->curr pointer is NULL. This is only possible when the list is empty.
        E it = this->curr->next->element;               // Remember element
        Link<E> *ltemp = this->curr->next;              // Remember link node
        if (this->tail == this->curr->next)
        {
            this->tail = this->curr; // If we are deleting the last element(which is also this->tail),the this->tail pointer will step back
        }
        this->curr->next = this->curr->next->next;
        delete ltemp;
        this->listSize--;
        if (this->curr->next == NULL) // If the last element is deleted, this->curr pointer will step back
        {
            if (this->curr != this->head) // Until it was also the first element. because if first element got deleted we can't step back
            {
                this->prev();
            }
        }
        return it;
    }
    void prev()
    { // Move this->curr one step left; no change if already at front
        if (this->curr == this->head)
        {
            cout << "Already at first position" << endl;
            return; // No previous element
        }
        Link<E> *temp = this->head;
        // March down list until we find the previous element
        while (temp->next != this->curr)
        {
            temp = temp->next;
        }
        this->curr = temp;
    }
    void moveToEnd() // Place curr at list end
    {
        this->curr = this->tail;
        if (this->curr != this->head)
        {
            this->prev();
        }
    }
};
#endif
