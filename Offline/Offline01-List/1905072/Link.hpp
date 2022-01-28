// Singly linked list node
template <typename E>
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
};