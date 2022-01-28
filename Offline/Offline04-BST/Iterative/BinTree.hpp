#ifndef __BIN_TREE__
#define __BIN_TREE__
#include "BinNode.hpp"
// Binary Tree implementation
template <typename E>
class BinTree
{
private:
    void operator=(const BinTree &) {} // Protect assignment
    BinTree(const BinTree &) {}        // Protect copy constructor

    // Private "helper" functions
    void clearhelp(BinNode<E> *root)
    {
        if (root == NULL) // Empty subtree, do nothing
            return;
        if (root->left() != NULL)     // To avoid extra call
            clearhelp(root->left());  // Clear left subtree
        if (root->right() != NULL)    // To avoid extra call
            clearhelp(root->right()); // Clear right subtree
        delete root;                  // Deallocate memory
    }
    // Preorder print
    void printhelp(BinNode<E> *root) const
    {
        if (root == NULL) // Empty subtree, do nothing
            return;
        cout << root->element(); // Print record

        if (root->isLeaf()) // If it's leaf, no need to print its empty childs
            return;

        cout << '(';
        if (root->left() != NULL)    // To avoid extra call
            printhelp(root->left()); // Go left subtree
        cout << ')';

        cout << '(';
        if (root->right() != NULL)    // To avoid extra call
            printhelp(root->right()); // Go right subtree
        cout << ')';
    }
    int heighthelp(BinNode<E> *root) const
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            /* compute the depth of each subtree */
            int lDepth = height(root->left());
            int rDepth = height(root->right());
            /* use the larger one */
            return max(lDepth, rDepth) + 1;
        }
    }
    int counthelp(BinNode<E> *root) const
    {
        if (root == NULL)
            return 0; // Nothing to count
        return 1 + count(root->left()) + count(root->right());
    }
    int postorderhelp(BinNode<E> *root, E *arr, int idx) const
    {
        if (root == NULL)
            return idx;
        if (root->left() != NULL)
            idx = postorderhelp(root->left(), arr, idx);
        if (root->right() != NULL)
            idx = postorderhelp(root->right(), arr, idx);
        arr[idx++] = root->element();
        return idx;
    }
    int preorderhelp(BinNode<E> *root, E *arr, int idx) const
    {
        if (root == NULL)
            return idx;
        arr[idx++] = root->element();
        if (root->left() != NULL)
            idx = preorderhelp(root->left(), arr, idx);
        if (root->right() != NULL)
            idx = preorderhelp(root->right(), arr, idx);
        return idx;
    }
    int inorderhelp(BinNode<E> *root, E *arr, int idx) const
    {
        if (root == NULL)
            return idx;
        if (root->left() != NULL)
            idx = inorderhelp(root->left(), arr, idx);
        arr[idx++] = root->element();
        if (root->right() != NULL)
            idx = inorderhelp(root->right(), arr, idx);
        return idx;
    }

protected:
    BinNode<E> *root; // Root of the BinTree
    int nodecount;    // Number of nodes in the BinTree

public:
    // Constructor
    BinTree()
    {
        root = NULL;
        nodecount = 0;
    }
    // Destructor
    virtual ~BinTree() { clearhelp(root); }
    // Reinitialize tree
    void clear()
    {
        clearhelp(root);
        root = NULL; // Because root now has garbage value, so setting it to NULL
        nodecount = 0;
    }

    // Return the number of nodes in the tree.
    int size() { return nodecount; }
    // Print the contents of the tree.
    void print() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            printhelp(root);
        cout << endl;
    }

    // Inorder traversal - left->root->right.
    E *inorder() const
    {
        E *arr = new E[nodecount];
        inorderhelp(root, arr, 0);
        return arr;
    }

    // Preorder traversal - root->left->right.
    E *preorder() const
    {
        E *arr = new E[nodecount];
        preorderhelp(root, arr, 0);
        return arr;
    }

    // Postorder traversal - left->right->root.
    E *postorder() const
    {
        E *arr = new E[nodecount];
        postorderhelp(root, arr, 0);
        return arr;
    }
    int height() const
    {
        return heighthelp(root);
    }
};
#endif
