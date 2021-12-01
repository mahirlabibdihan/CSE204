// Singly linked list node
template <typename T>
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
};