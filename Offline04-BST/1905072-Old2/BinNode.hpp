#ifndef __BIN_NODE__
#define __BIN_NODE__
// Simple binary tree node implementation
template <typename E>
class BinNode
{
protected:
    E it;                   // The node’s value
    BinNode<E> *leftChild;  // Pointer to leftChild child
    BinNode<E> *rightChild; // Pointer to right child
public:
    // Two constructors -- with and without initial values
    BinNode()
    {
        leftChild = rightChild = NULL;
    }
    BinNode(E e, BinNode<E> *l = NULL, BinNode<E> *r = NULL)
    {
        it = e;
        leftChild = l;
        rightChild = r;
    }
    // Destructor
    virtual ~BinNode() {}
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }

    // Functions to set and return the children
    BinNode<E> *left() const { return leftChild; }
    void setLeft(BinNode<E> *lc) { leftChild = lc; }
    BinNode<E> *right() const { return rightChild; }
    void setRight(BinNode<E> *rc) { rightChild = rc; }
    // Return: true if it is a leaf, false otherwise
    bool isLeaf() const { return (leftChild == NULL) && (rightChild == NULL); }
    // Inorder traversal
    void inorder() const
    {
        // Traverse left Sub Tree
        if (left() != NULL)
            left()->inorder();
        // Print
        cout << element() << ' ';
        // Traverse right Sub Tree
        if (right() != NULL)
            right()->inorder();
    }
    // Preorder traversal
    void preorder() const
    {
        // Print
        cout << element() << ' ';
        // Traverse left Sub Tree
        if (left() != NULL)
            left()->preorder();
        // Traverse right Sub Tree
        if (right() != NULL)
            right()->preorder();
    }
    // Postorder traversal
    void postorder() const
    {
        // Traverse left Sub Tree
        if (left() != NULL)
            left()->postorder();
        // Traverse right Sub Tree
        if (right() != NULL)
            right()->postorder();
        // Print
        cout << element() << ' ';
    }
};
#endif