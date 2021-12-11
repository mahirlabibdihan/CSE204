#ifndef __BIN_TREE__
#define __BIN_TREE__
#include "BinNode.hpp"
// Binary Search Tree implementation for the Dictionary ADT
template <typename E>
class BinTree
{
protected:
    BinNode<E> *root; // Root of the BinTree
    int nodecount;    // Number of nodes in the BinTree
    // Private "helper" functions
    void printhelp(BinNode<E> *) const;
    void clearhelp(BinNode<E> *);
    virtual BinNode<E> *inserthelp(BinNode<E> *, const E &) = 0;
    virtual BinNode<E> *removehelp(BinNode<E> *, const E &) = 0;
    virtual BinNode<E> *findhelp(BinNode<E> *, const E &) const = 0;

public:
    BinTree()
    {
        root = NULL;
        nodecount = 0;
    }                                       // Constructor
    virtual ~BinTree() { clearhelp(root); } // Destructor
    void clear()                            // Reinitialize tree
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }
    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const E &it)
    {
        root = inserthelp(root, it);
        nodecount++;
    }
    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    BinNode<E> *remove(const E &it)
    {
        BinNode<E> *temp = findhelp(root, it); // First find it
        if (temp != NULL)
        {
            root = removehelp(root, it);
            nodecount--;
        }
        return temp;
    }
    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    BinNode<E> *find(const E &it) const { return findhelp(root, it); }
    // Return the number of records in the dictionary.
    int size() { return nodecount; }
    void print() const
    { // Print the contents of the BinTree
        if (root == NULL)
            cout << "The Tree is empty";
        else
            printhelp(root);
        cout << endl;
    }
    void inorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->inorder();
        cout << endl;
    }
    void preorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->preorder();
        cout << endl;
    }
    void postorder() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            root->postorder();
        cout << endl;
    }
};

template <typename E>
void BinTree<E>::clearhelp(BinNode<E> *root)
{
    if (root == NULL)
        return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}
template <typename E>
void BinTree<E>::printhelp(BinNode<E> *root) const
{
    if (root == NULL)
        return;              // Empty tree
    cout << root->element(); // Print node value
    if (root->isLeaf())
        return;
    cout << '(';
    printhelp(root->left()); // Do left subtree
    cout << ')';

    cout << '(';
    printhelp(root->right()); // Do right subtree
    cout << ')';
}
#endif
