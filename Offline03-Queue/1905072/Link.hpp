#ifndef __LINK__
#define __LINK__
// Singly linked list node
template <typename T>
class Link
{
public:
    T element;  // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const T &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL) { next = nextval; }
};
#endif