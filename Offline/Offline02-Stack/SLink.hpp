#ifndef __S_LINK__
#define __S_LINK__
#include <cstddef>
// Singly linked list node
// Singly linked list node with freelist support
#include "Link.hpp"
template <typename E>
class SLink : public Link<E>
{
public:
    // Constructors
    SLink(const E &elemval, Link<E> *nextval = NULL)
    {
        this->element = elemval;
        this->next = nextval;
    }
    SLink(Link<E> *nextval = NULL) { this->next = nextval; }
};
#endif