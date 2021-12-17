#ifndef __NODE__
#define __NODE__
// Simple binary tree node implementation
template <typename E>
class Node
{
private:
    E it; // The node’s value
public:
    // Two constructors -- with and without initial values
    BinNode()
    {
        it = E();
    }
    // Destructor
    virtual ~BinNode() {}
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }
    // Return: true if it is a leaf, false otherwise
    virtual bool isLeaf() const;
};
#endif