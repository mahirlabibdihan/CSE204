#ifndef __BIN_NODE__
#define __BIN_NODE__
// Simple binary tree node implementation
template <typename E>
class BinNode
{
private:
    E it;                   // The node’s value
    BinNode<E> *leftChild;  // Pointer to leftChild child
    BinNode<E> *rightChild; // Pointer to right child
public:
    // Two constructors -- with and without initial values
    BinNode() { leftChild = rightChild = NULL; }
    BinNode(E e, BinNode<E> *l = NULL, BinNode<E> *r = NULL)
    {
        it = e;
        leftChild = l;
        rightChild = r;
    }
    ~BinNode() {} // Destructor
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }

    // Functions to set and return the children
    inline BinNode<E> *left() const { return leftChild; }
    void setLeft(BinNode<E> *b) { leftChild = b; }
    inline BinNode<E> *right() const { return rightChild; }
    void setRight(BinNode<E> *b) { rightChild = b; }
    // Return true if it is a leaf, false otherwise
    bool isLeaf() const { return (leftChild == NULL) && (rightChild == NULL); }
    // Inorder traversal
    void inorder() const
    {
        // Traversal behavior for internal nodes
        if (left() != NULL)
            left()->inorder();
        cout << element() << ' ';
        if (right() != NULL)
            right()->inorder();
    }
    // Preorder traversal
    void preorder() const
    {
        // Traversal behavior for internal nodes
        cout << element() << ' ';
        if (left() != NULL)
            left()->preorder();
        if (right() != NULL)
            right()->preorder();
    }
    // Postorder traversal
    void postorder() const
    {
        // Traversal behavior for internal nodes
        if (left() != NULL)
            left()->postorder();
        if (right() != NULL)
            right()->postorder();
        cout << element() << ' ';
    }
};
#endif