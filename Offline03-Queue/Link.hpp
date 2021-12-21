#ifndef __LINK__
#define __LINK__
#include <iostream>
using namespace std;
// Singly linked list node
/*template <typename E>
class Link
{
public:
    E value;
    Link *next;
    // Constructors
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
    Link(const E &value, Link *next = NULL)
    {
        this->value = value;
        this->next = next;
    }
};*/
// Singly linked list node with freelist support
template <typename E>
class Link
{
private:
    static Link<E> *freelist; // Reference to freelist head
public:
    E element;     // Value for this node
    Link<E> *next; // Point to next node in list
    // Constructors
    Link()
    {
    }
    virtual ~Link()
    {
        // cout << "Link Delete" << endl;
    }
    void *operator new(size_t t)
    { // Overloaded new operator
        if (freelist == NULL)
            return ::new Link<E>(); // Create space
        Link<E> *temp = freelist;   // Can take from freelist
        freelist = freelist->next;
        return temp; // Return the link
    }
    // Overloaded delete operator
    void operator delete(void *ptr)
    {
        // cout << "Link Delete override" << endl;
        ((Link<E> *)ptr)->next = freelist; // Put on freelist
        freelist = (Link<E> *)ptr;
    }
    static void clearFreeList()
    {
        while (freelist != NULL)
        {
            Link<E> *temp = freelist; // Can take from freelist
            freelist = freelist->next;
            ::delete temp;
        }
    }
};
// The freelist head pointer is actually created here
template <typename E>
Link<E> *Link<E>::freelist = NULL;
#endif