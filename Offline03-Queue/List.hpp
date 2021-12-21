#ifndef __LIST__
#define __LIST__
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
    virtual int search(const E &item) const = 0;
};
#endif