#ifndef __A_BIN_TREE__
#define __A_BIN_TREE__
#include "ABinNode.hpp"
#include <iostream>
using namespace std;
// Binary Tree implementation
template <typename E>
class ABinTree
{
private:
    static const int defaultSize = 10;
    ABinNode<E> *tree;                  // Pointer to the heap array
    int maxsize;                        // Maximum size of the heap
    int n;                              // Number of elements now in the heap
    void operator=(const ABinTree &) {} // Protect assignment
    ABinTree(const ABinTree &) {}       // Protect copy constructor
    // Private "helper" functions

    // Preorder print
    void printhelp(int pos) const
    {
        if (tree[pos] == NULL || pos >= n) // Empty subtree, do nothing
            return;
        cout << tree[pos]; // Print record

        if (isLeaf(pos)) // If it's leaf, no need to print its empty childs
            return;

        cout << '(';
        if (this->left(pos) < n)     // To avoid extra call
            printhelp(this->left()); // Go left subtree
        cout << ')';

        cout << '(';
        if (this->right(pos) < n)     // To avoid extra call
            printhelp(this->right()); // Go right subtree
        cout << ')';
    }

public:
    // Constructor
    ABinTree()
    {
    }
    ABinTree(int size = defaultSize)
    {
        maxsize = size;
        tree = new ABinNode<E>[maxsize];
        n = 0;
    }
    ABinTree(ABinNode<E> *arr, int n, int size = defaultSize)
    {
        maxsize = size;
        tree = arr;
        this->n = n;
    }
    // Destructor
    virtual ~ABinTree()
    {
        delete[] tree;
    }
    // Reinitialize tree
    void clear()
    {
        n = 0;
    }
    int size() const // Return current tree size
    {
        return n;
    }
    bool isLeaf(int pos) const // True if pos is a leaf
    {
        return (pos >= n / 2) && (pos < n);
    }
    int left(int pos) const // Return leftchild position
    {
        return 2 * pos + 1;
    }
    void setLeft(int pos, E e)
    {
        tree[left(pos)].setElement(e);
    }
    int right(int pos) const
    {
        return 2 * pos + 2; // Return rightchild position
    }
    void setRight(int pos, E e)
    {
        tree[right(pos)].setElement(e);
    }
    int parent(int pos) const // Return parent position
    {
        return (pos - 1) / 2;
    }
    // Print the contents of the tree.
    void print() const
    {
        if (n == 0)
            cout << "The Tree is empty";
        else
            printhelp(0);
        cout << endl;
    }
    void inorderHelp(int pos) const
    {
        if (tree[pos].element() == (E)NULL || pos >= n)
            return;
        // Traverse left Sub Tree
        if (this->left(pos) < n)
            inorderHelp(this->left(pos));
        // Print
        cout << tree[pos].element() << ' ';
        // Traverse right Sub Tree
        if (this->right() < n)
            inorderHelp(this->right(pos));
    }
    // Inorder traversal - left->root->right.
    void inorder() const
    {
        if (n == 0)
            cout << "The Tree is empty";
        else
            inorderHelp(0);
        cout << endl;
    }
    void preorderHelp(int pos) const
    {
        if (tree[pos].element() == (E)NULL || pos >= n)
            return;
        // Print
        cout << tree[pos].element() << ' ';
        // Traverse left Sub Tree
        if (this->left(pos) < n)
            preorderHelp(this->left(pos));
        // Traverse right Sub Tree
        if (this->right() < n)
            preorderHelp(this->right(pos));
    }

    // Preorder traversal - root->left->right.
    void preorder() const
    {
        if (n == 0)
            cout << "The Tree is empty";
        else
            preorderHelp(0);
        cout << endl;
    }
    void postorderHelp(int pos) const
    {
        if (tree[pos].element() == (E)NULL || pos >= n)
            return;
        // Traverse left Sub Tree
        if (this->left(pos) < n)
            postorderHelp(this->left(pos));
        // Traverse right Sub Tree
        if (this->right() < n)
            postorderHelp(this->right(pos));
        // Print
        cout << tree[pos] << ' ';
    }
    // Postorder traversal - left->right->root.
    void postorder() const
    {
        if (n == 0)
            cout << "The Tree is empty";
        else
            postorderHelp(0);
        cout << endl;
    }
};
#endif
