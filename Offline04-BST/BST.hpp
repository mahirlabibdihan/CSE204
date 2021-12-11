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
            root->setLeft(inserthelp(root->left(), it));
        else
            root->setRight(inserthelp(root->right(), it));
        return root; // Return tree with node inserted
    }
    BinNode<E> *deletemin(BinNode<E> *root)
    {
        if (root->left() == NULL) // Found min
            return root->right();
        else
        { // Continue left
            root->setLeft(deletemin(root->left()));
            return root;
        }
    }
    BinNode<E> *getmin(BinNode<E> *root)
    {
        if (root->left() == NULL)
            return root;
        else
            return getmin(root->left());
    }
    // Remove a node with key value k
    // Return: The tree with the node removed
    BinNode<E> *removehelp(BinNode<E> *root, const E &it)
    {
        if (root == NULL)
            return NULL; // k is not in tree
        else if (it < root->element())
        {
            if (root->left() != NULL)
                root->setLeft(removehelp(root->left(), it)); // Checking in left subtree
        }
        else if (it > root->element())
        {
            if (root->right() != NULL)
                root->setRight(removehelp(root->right(), it)); // Checking in right subtree
        }
        else
        { // Found: remove it
            BinNode<E> *temp = root;
            if (root->left() == NULL && root->right() == NULL)
            {                // No
                root = NULL; // so point to NULL
                delete temp;
            }
            else if (root->left() == NULL)
            {                         // Only a right child
                root = root->right(); // so point to right
                delete temp;
            }
            else if (root->right() == NULL)
            {                        // Only a left child
                root = root->left(); // so point to left
                delete temp;
            }
            else
            {
                // Both children are non-empty
                BinNode<E> *temp = getmin(root->right());
                root->setElement(temp->element());
                root->setRight(deletemin(root->right()));
                delete temp;
            }
        }
        return root;
    }
    BinNode<E> *findhelp(BinNode<E> *root, const E &it) const
    {
        if (root == NULL)
            return NULL; // Empty tree
        if (it < root->element())
            return findhelp(root->left(), it); // Check left
        else if (it > root->element())
            return findhelp(root->right(), it); // Check right
        else
            return root; // Found it
    }

public:
    BST() {}  // Constructor
    ~BST() {} // Destructor
};
#endif
