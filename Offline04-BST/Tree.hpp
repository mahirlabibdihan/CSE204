#ifndef __TREE__
#define __TREE__
// Binary Tree implementation
template <typename E>
class Tree
{
private:
    void operator=(const Tree &) {} // Protect assignment
    Tree(const Tree &) {}           // Protect copy constructor

    Node<E> *root; // Root of the Tree
    int nodecount; // Number of nodes in the BinTree
public:
    // Constructor
    Tree() {}
    // Destructor
    virtual ~Tree() {}
    // Reinitialize tree
    virtual void clear();

    // Return the number of nodes in the tree.
    virtual int size() const;
    virtual int height() const;
    // Print the contents of the tree.
    virtual void print() const;
};
#endif
