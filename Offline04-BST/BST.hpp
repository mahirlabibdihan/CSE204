#ifndef __BST__
#define __BST__
#include "BinTree.hpp"
#include "BSTNode.hpp"

// Binary Search Tree implementation
template <typename Key, typename E>
class BST : public BinTree<E>
{
private:
    BinNode<E> *inserthelp(BinNode<E> *root, const Key &k, const E &e)
    {
        if (root == NULL) // Empty tree: create node
            return new BSTNode<Key, E>(k, e, NULL, NULL);
        if (k < ((BSTNode<Key, E> *)root)->key())
        { // 'k' is smaller than current node, so go left
            root->setLeft(inserthelp(root->left(), k, e));
        }
        else
        { // 'k' is greater than current node, so go right
            root->setRight(inserthelp(root->right(), k, e));
        }
        return root; // Return tree with node inserted
    }
    BinNode<E> *deleteMin(BinNode<E> *root)
    {
        if (root->left() == NULL)
        { // Found min
            // min has either right child or no child
            if (root->right() == NULL) // No child
            {
                return NULL;
            }
            else // Has right child
            {
                return root->right();
            }
        }
        else
        { // Continue left
            root->setLeft(deleteMin(root->left()));
            return root;
        }
    }
    BinNode<E> *getMin(BinNode<E> *root) const
    {
        if (root->left() == NULL)
        { // Found min
            return root;
        }
        else
        { // Continue left
            return getMin(root->left());
        }
    }
    BinNode<E> *deleteMax(BinNode<E> *root)
    {
        if (root->right() == NULL)
        { // Found max
            // min has either left child or no child
            if (root->left() == NULL) // No child
            {
                return NULL;
            }
            else // Has left child
            {
                return root->left();
            }
        }
        else
        { // Continue right
            root->setRight(deleteMax(root->right()));
            return root;
        }
    }
    BinNode<E> *getMax(BinNode<E> *root) const
    {
        if (root->right() == NULL)
        { // Found max
            return root;
        }
        else
        { // Continue right
            return getMax(root->right());
        }
    }
    BinNode<E> *removehelp(BinNode<E> *root, const Key &k)
    {
        if (root == NULL) // 'k' is not in the tree
        {
            return NULL;
        }
        if (k < ((BSTNode<Key, E> *)root)->key())
        {
            // 'k'' is smaller than current key, so go left
            if (root->left() != NULL) // To avoid extra call
            {
                root->setLeft(removehelp(root->left(), k)); // Check left
            }
        }
        else if (k > ((BSTNode<Key, E> *)root)->key())
        {
            // 'k' is greater than current key, so go right
            if (root->right() != NULL) // To avoid extra call
            {
                root->setRight(removehelp(root->right(), k)); // Check right
            }
        }
        else
        { // Found: remove it
            BinNode<E> *temp = root;
            if (root->left() == NULL && root->right() == NULL)
            {
                root = NULL; // No children, so point to NULL
            }
            else if (root->left() == NULL)
            {
                root = root->right(); // No left child,so point to right
            }
            else if (root->right() == NULL)
            {
                root = root->left(); // No right child,so point to left
            }
            else
            {
                // Both children are non-empty
                // We need to replace this node with inorder successor or predecessor
                // temp = getMin(root->right());    // Inorder Successor
                temp = getMax(root->left()); // Inorder predecessor
                ((BSTNode<Key, E> *)root)->setKey(((BSTNode<Key, E> *)temp)->key());
                root->setElement(temp->element());
                // root->setRight(deleteMin(root->right()));
                root->setLeft(deleteMax(root->left()));
            }
            delete temp; // Deallocating memory after removing node
        }
        return root;
    }
    E findhelp(BinNode<E> *root, const Key &k) const
    {
        if (root == NULL)
        { // 'k' is not in the tree
            return (E)NULL;
        }
        if (k < ((BSTNode<Key, E> *)root)->key())
        {
            // 'k' is smaller than current key
            return findhelp(root->left(), k); // Check left
        }
        else if (k > ((BSTNode<Key, E> *)root)->key())
        {
            // 'k' is greater than current key
            return findhelp(root->right(), k); // Check right
        }
        else
        { // Found it
            return root->element();
        }
    }

public:
    BST() {}  // Constructor
    ~BST() {} // Destructor
    // Insert a record into the tree.
    // k: Key value of the record.
    // e: The record to insert.
    void insert(const Key &k, const E &e)
    {
        this->root = inserthelp(this->root, k, e);
        this->nodecount++; // Increasing total node count
    }
    // Remove a record from the tree.
    // k: Key value of the record to remove
    // Return: The record removed, or NULL if there is none.
    E remove(const Key &k)
    {
        E temp = findhelp(this->root, k); // First find it
        if (temp != (E)NULL)
        {
            this->root = removehelp(this->root, k);
            this->nodecount--;
        }
        return temp;
    }
    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    E removeAny()
    { // Delete min value
        if (this->root != NULL)
        {
            E temp = getMin(this->root)->element();
            this->root = deleteMin(this->root);
            this->nodecount--;
            return temp;
        }
        else
            return (E)NULL;
    }
    // Return Record with key value 'k', NULL if none exist.
    // If multiple nodes match 'k', return an arbitrary one.
    E find(const Key &k) const
    {
        return findhelp(this->root, k);
    }
};
#endif
