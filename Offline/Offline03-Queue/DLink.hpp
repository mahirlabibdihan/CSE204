#ifndef __D_LINK__
#define __D_LINK__
// Doubly linked list node
// Doubly linked list link node with freelist support
#include "Link.hpp"
template <typename E>
class DLink : public Link<E>
{
public:
    Link<E> *prev; // Pointer to previous node
    // Constructors
    DLink(const E &it, Link<E> *prevp, Link<E> *nextp)
    {
        this->element = it;
        this->prev = prevp;
        this->next = nextp;
    }
    DLink(Link<E> *prevp = NULL, Link<E> *nextp = NULL)
    {
        this->prev = prevp;
        this->next = nextp;
    }
    ~DLink()
    {
    }
};
#endif