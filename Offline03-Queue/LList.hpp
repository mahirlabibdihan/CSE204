#ifndef __L_LIST__
#define __L_LIST__
#include <iostream>
#include "Link.hpp"
#include "List.hpp"
using namespace std;
/*
In this implementation we are actually pointing the previous node of the current element.
Because when we will remove an element we will need the pointer to the previous node.
We can get the previous node also by traversing from the beginning but that will take extra O(n) time.
To avoid that we will always point to the previous node.
So, when when current element is the first one we have to point to the previous node. 
So we need to take an extra head node. This node will be available in the empty list.
*/
/* 
Assume,curr pointer = ^
            head->[0th element]->[1th]->[2th]->........->tail[n-1 th]->NULL
Currpos=0:   ^
Currpos=1:              ^
Remove:     head->[0th element]->[2th]->........->[n-2 th]->tail[n-1 th]->NULL
            head->[0th element]->[1th]->........->[n-2 th]->tail[n-1 th]->NULL
                        ^
Insert:     head->[0th element]->[1th]->[2th]->........->[n-2 th]->tail[n-1 th]->NULL
                        ^
Currpos=n-1:                                                  ^
Remove:     head->[0th element]->[1th]->[2th]->........->[n-3th]->tail[n-2 th]->NULL
                                                                            ^
            head->[0th element]->[1th]->[2th]->........->[n-2th]->tail[n-1 th]->NULL
                                                              ^      (curr pointer steps back.If the next node of curr pointer is NULL,then remove operation will be failed.)
                                                     

*/
// Linked list implementation
template <typename E>
class LList : public List<E>
{
protected:
    int listSize;
    Link<E> *head;
    Link<E> *tail;
    Link<E> *curr;
    void init()
    { // Intialization helper method
        listSize = 0;
    }
    void removeall()
    { // Return link nodes to free store
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList()
    {
        init();
    }
    virtual ~LList()
    {
        // Link<E>::clearFreeList();
        removeall();
    }
    void moveToStart() // Place curr at list start
    {
        curr = head;
    }
    // Move curr one step right; no change if already at end
    void next()
    {
        if (head == tail)
        {
            cout << "Already at last position" << endl;
            return;
        }
        else if (curr->next == tail)
        {
            cout << "Already at last position" << endl;
            return;
        }
        curr = curr->next;
    }
    int length() const
    {
        return listSize;
    }
    int currPos() const
    { // Return the position of the current element
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
        {
            temp = temp->next;
        }
        return i;
    }
    void moveToPos(int pos)
    { // Move down list to "pos" position
        if ((pos < 0) || (pos >= listSize))
        {
            cout << "Position out of range" << endl;
            return;
        }
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }
    const E &getValue() const
    { // Return current element
        Assert(curr->next != NULL, "Empty list");
        return curr->next->element;
    }
    int search(const E &item) const
    {
        Link<E> *temp = head->next;
        for (int i = 0; i < listSize; i++)
        {
            if (temp->element == item)
            {
                return i;
            }
            temp = temp->next;
        }
        delete temp;
        return -1; // item not found
    }
};
#endif
