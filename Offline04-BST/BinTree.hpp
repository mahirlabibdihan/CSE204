#ifndef __BIN_TREE__
#define __BIN_TREE__
#include "BinNode.hpp"
// Binary Tree implementation
template <typename E>
class BinTree
{
public:
    BinNode<E> *root; // Root of the BinTree
    int nodecount;    // Number of nodes in the BinTree
    // Private "helper" functions
    void clearhelp(BinNode<E> *root)
    {
        if (root == NULL)
            return;
        if (root->left() != NULL)     // To avoid extra call
            clearhelp(root->left());  // Clear left subtree
        if (root->right() != NULL)    // To avoid extra call
            clearhelp(root->right()); // Clear right subtree
        delete root;
    }
    // Preorder print
    void printhelp(BinNode<E> *root) const
    {
        if (root == NULL)
            return;              // Empty tree
        cout << root->element(); // Print node value

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
    virtual BinNode<E> *inserthelp(BinNode<E> *, const E &) = 0;
    virtual BinNode<E> *removehelp(BinNode<E> *, const E &) = 0;
    virtual BinNode<E> *findhelp(BinNode<E> *, const E &) const = 0;

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
    // Insert a node into the tree.
    // it: Value of the node to insert.
    void insert(const E &it)
    {
        root = inserthelp(root, it);
        nodecount++; // Increasing total node count
    }
    // Remove a node from the tree.
    // it: Value of node to remove.
    // Return: True if removed, false otherwise.
    bool remove(const E &it)
    {
        int temp = size();
        root = removehelp(root, it);
        return temp > size();
    }
    // Return some node matching 'it', NULL if none exist.
    // If multiple nodes match "k", return an arbitrary one.
    BinNode<E> *find(const E &it) const { return findhelp(root, it); }
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
    void inorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->inorder();
        cout << endl;
    }
    // Preorder traversal - root->left->right.
    void preorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->preorder();
        cout << endl;
    }
    // Postorder traversal - left->right->root.
    void postorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->postorder();
        cout << endl;
    }
};
#endif
