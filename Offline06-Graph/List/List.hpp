#ifndef __LIST__
#define __LIST__
#include <iostream>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
template <typename E>
class List
{
private:
    void operator=(const List &) {} // Protect assignment
    List(const List &) {}           // Protect copy constructor
public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;
    virtual void insert(const E &item) = 0;
    virtual void append(const E &item) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() const = 0;
    virtual int currPos() const = 0;
    virtual void moveToPos(int pos) = 0;
    virtual const E &getValue() const = 0;
};
template <typename E>
void replace(List<E> *lst, int pos, const E &item)
{
    lst->moveToPos(pos);
    lst->remove();
    lst->insert(item);
}
template <typename E>
int find(List<E> *lst, const E &item)
{
    int curr = lst->currPos();
    for (lst->moveToStart(); lst->currPos() < lst->length(); lst->next())
    {
        if (item == lst->getValue())
        {
            return lst->currPos();
        }
        if (lst->currPos() + 1 == lst->length())
        {
            break;
        }
    }
    lst->moveToPos(curr);
    return -1; // item not found
}
template <typename E>
ostream &operator<<(ostream &os, List<E> *lst)
{
    int curr = lst->currPos();
    os << "<";
    for (lst->moveToStart(); lst->currPos() < lst->length(); lst->next())
    {
        if (lst->currPos() == curr)
        {
            os << "| ";
        }
        os << lst->getValue() << ' ';

        if (lst->currPos() + 1 == lst->length())
        {
            break;
        }
    }
    lst->moveToPos(curr);
    os << ">";
    return os;
}
#endif