#ifndef __A_BIN_NODE__
#define __A_BIN_NODE__
// Simple binary tree node implementation
template <typename E>
class ABinNode
{
protected:
    E it; // The node’s value

public:
    // Two constructors -- with and without initial values
    ABinNode()
    {
        it = E();
    }
    ABinNode(E e)
    {
        it = e;
    }
    // Destructor
    virtual ~ABinNode() {}
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }
};
#endif