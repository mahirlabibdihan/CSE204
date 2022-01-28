#ifndef __BST_NODE__
#define __BST_NODE__
#include "BinNode.hpp"
// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E>
{
private:
    Key k; // The node’s key
public:
    // Two constructors -- with and without initial values
    BSTNode()
    {
    }
    BSTNode(Key K, E e, BinNode<E> *l = NULL, BinNode<E> *r = NULL) : BinNode<E>::BinNode(e, l, r)
    {
        k = K;
    }
    ~BSTNode() {} // Destructor
    // Functions to set and return the value and key
    const Key &key() const { return k; }
    void setKey(const Key &K) { k = K; }
};
#endif