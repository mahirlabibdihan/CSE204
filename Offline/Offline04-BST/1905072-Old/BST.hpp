#ifndef __BST__
#define __BST__
#include "BinTree.hpp"
// Binary Search Tree implementation
template <typename E>
class BST : public BinTree<E>
{
private:
    BinNode<E> *inserthelp(BinNode<E> *root, const E &it)
    {
        if (root == NULL) // Empty tree: create node
            return new BinNode<E>(it, NULL, NULL);
        if (it < root->element())
        { // 'it' is smaller than current node, so go left
            root->setLeft(inserthelp(root->left(), it));
        }
        else
        { // 'it' is greater than current node, so go right
            root->setRight(inserthelp(root->right(), it));
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
    BinNode<E> *removehelp(BinNode<E> *root, const E &it)
    {
        if (root == NULL) // 'it' is not in the tree
        {
            return NULL;
        }
        if (it < root->element())
        {
            // Target node is smaller than current node, so go left
            if (root->left() != NULL) // To avoid extra call
            {
                root->setLeft(removehelp(root->left(), it)); // Check left
            }
        }
        else if (it > root->element())
        {
            // Target node is greater than current node, so go right
            if (root->right() != NULL) // To avoid extra call
            {
                root->setRight(removehelp(root->right(), it)); // Check right
            }
        }
        else
        { // Found: remove 'it'
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
                temp = getMin(root->right());
                root->setElement(temp->element());
                root->setRight(deleteMin(root->right()));
            }
            this->nodecount--; // Decreasing total node count
            delete temp;       // Deallocating memory after removing node
        }
        return root;
    }
    BinNode<E> *findhelp(BinNode<E> *root, const E &it) const
    {
        if (root == NULL)
        { // Empty tree
            return NULL;
        }
        if (it < root->element())
        {
            // Target node is smaller the current node
            return findhelp(root->left(), it); // Check left
        }
        else if (it > root->element())
        {
            // Target node is greater the current node
            return findhelp(root->right(), it); // Check right
        }
        else
        { // Found 'it'
            return root;
        }
    }

public:
    BST() {}  // Constructor
    ~BST() {} // Destructor
};
#endif
