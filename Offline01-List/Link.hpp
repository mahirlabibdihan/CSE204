#include <cstddef>
// Singly linked list node
/*template <typename T>
class Link
{
public:
    T value;
    Link *next;
    // Constructors
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
    Link(const T &value, Link *next = NULL)
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
    E element;  // Value for this node
    Link *next; // Point to next node in list
    // Constructors
    Link(const E &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL) { next = nextval; }
    void *operator new(size_t t)
    { // Overloaded new operator
        if (freelist == NULL)
            return ::new Link;    // Create space
        Link<E> *temp = freelist; // Can take from freelist
        freelist = freelist->next;
        return temp; // Return the link
    }
    // Overloaded delete operator
    void operator delete(void *ptr)
    {
        ((Link<E> *)ptr)->next = freelist; // Put on freelist
        freelist = (Link<E> *)ptr;
    }
};
// The freelist head pointer is actually created here
template <typename E>
Link<E> *Link<E>::freelist = NULL;