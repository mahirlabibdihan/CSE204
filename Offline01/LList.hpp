#ifndef __L_LIST__
#define __L_LIST__
#include <iostream>
#include "Link.hpp"
#include "List.hpp"
using namespace std;

// Linked list implementation
template <typename T>
class LList : public List<T>
{
private:
    Link<T> *head;
    Link<T> *tail;
    Link<T> *curr;
    int listSize;
    void init()
    { // Intialization helper method
        curr = tail = head = new Link<T>;
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
    LList(int maxSize = 0)
    {
        init();
    }
    LList(int *arr, int listSize, int maxSize = 0)
    {
        init();
        // Copying elements form array to list
        for (int i = 0; i < listSize; i++)
        {
            this->append(arr[i]);
        }
    }
    ~LList()
    {
        removeall();
    }
    void clear()
    {
        removeall();
        init();
    }
    void insert(const T &it)
    { // Insert "it" at current position
        curr->next = new Link<T>(it, curr->next);
        if (tail == curr)
        {
            tail = curr->next; // New tail
        }
        listSize++;
    }
    void append(const T &it)
    { // Append "it" to list
        tail = tail->next = new Link<T>(it);
        listSize++;
    }
    T remove()
    {
        // Remove and return current value
        if (curr->next == NULL)
        {
            cout << "No element" << endl;
            exit(-1);
        }
        T it = curr->next->value;    // Remember value
        Link<T> *ltemp = curr->next; // Remember link node
        if (tail == curr->next)
        {
            tail = curr;
        }
        curr->next = curr->next->next;
        delete ltemp;
        listSize--;
        if (curr->next == NULL)
        {
            if (curr != head)
            {
                this->prev();
            }
        }
        return it;
    }
    void moveToStart() // Place curr at list start
    {
        curr = head;
    }
    void moveToEnd() // Place curr at list end
    {
        curr = tail;
        this->prev();
    }
    void prev()
    { // Move curr one step left; no change if already at front
        if (curr == head)
        {
            cout << "Already at first position" << endl;
            exit(-1); // No previous value
        }
        Link<T> *temp = head;
        // March down list until we find the previous value
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }
    // Move curr one step right; no change if already at end
    void next()
    {
        if (curr->next == tail)
        {
            cout << "Already at last position" << endl;
            exit(-1);
        }
        curr = curr->next;
    }
    int length() const
    {
        return listSize;
    }
    int currPos() const
    { // Return the position of the current element
        Link<T> *temp = head;
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
            exit(-1);
        }
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }
    const T &getValue() const
    { // Return current value
        if (curr->next == NULL)
        {
            cout << "No current element" << endl;
            exit(-1);
        }
        return curr->next->value;
    }
    int Search(const T &item) const
    {
        Link<T> *temp = head->next;
        for (int i = 0; i < listSize; i++)
        {
            if (temp->value == item)
            {
                return i;
            }
            temp = temp->next;
        }
        return -1; // item not found
    }
};
#endif
