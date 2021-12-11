#ifndef __BIN_NODE__
#define __BIN_NODE__
// Binary tree node abstract class
template <typename E>
class BinNode
{
public:
    virtual ~BinNode() {} // Base destructor
    // Return the node’s value
    virtual const E &element() const = 0;
    // Set the node’s value
    virtual void setElement(const E &) = 0;
    // Return the node’s left child
    virtual BinNode *left() const = 0;
    // Set the node’s left child
    virtual void setLeft(BinNode *) = 0;
    // Return the node’s right child
    virtual BinNode *right() const = 0;
    // Set the node’s right child
    virtual void setRight(BinNode *) = 0;
    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() const = 0;
    // Inorder traversal
    virtual void inorder() const = 0;
    // Preorder traversal
    virtual void preorder() const = 0;
    // Postorder traversal
    virtual void postorder() const = 0;
};
#endif