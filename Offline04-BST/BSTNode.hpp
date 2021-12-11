#include "BinNode.hpp"
// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E>
{
private:
    Key k;       // The node’s key
    E it;        // The node’s value
    BSTNode *lc; // Pointer to lc child
    BSTNode *rc; // Pointer to right child
public:
    // Two constructors -- with and without initial values
    BSTNode() { lc = rc = NULL; }
    BSTNode(Key K, E e, BSTNode *l = NULL, BSTNode *r = NULL)
    {
        k = K;
        it = e;
        lc = l;
        rc = r;
    }
    ~BSTNode() {} // Destructor
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }
    Key &key() /*const*/ { return k; }
    void setKey(const Key &K) { k = K; }
    // Functions to set and return the children
    inline BSTNode *left() const { return lc; }
    void setLeft(BinNode<E> *b) { lc = (BSTNode *)b; }
    inline BSTNode *right() const { return rc; }
    void setRight(BinNode<E> *b) { rc = (BSTNode *)b; }
    // Return true if it is a leaf, false otherwise
    bool isLeaf() const { return (lc == NULL) && (rc == NULL); }
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