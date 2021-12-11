#ifndef __BIN_TREE__
#define __BIN_TREE__
#include "BSTNode.hpp"
#include "Dictionary.hpp"
// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BinTree : public Dictionary<Key, E>
{
private:
    BinNode<E> *root; // Root of the BinTree
    int nodecount;    // Number of nodes in the BinTree
    // Private "helper" functions
    void clearhelp(BSTNode<Key, E> *);
    BinNode<E> *inserthelp(BinNode<E> *, const Key &, const E &);
    BSTNode<Key, E> *deletemin(BSTNode<Key, E> *);
    BSTNode<Key, E> *getmin(BSTNode<Key, E> *);
    BSTNode<Key, E> *removehelp(BSTNode<Key, E> *, const Key &);
    E findhelp(BSTNode<Key, E> *, const Key &) const;
    void printhelp(BSTNode<Key, E> *) const;

public:
    BinTree()
    {
        root = NULL;
        nodecount = 0;
    }                               // Constructor
    ~BinTree() { clearhelp(root); } // Destructor
    void clear()                    // Reinitialize tree
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }
    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key &k, const E &e)
    {
        root = inserthelp(root, k, e);
        nodecount++;
    }
    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    E remove(const Key &k)
    {
        E temp = findhelp(root, k); // First find it
        if (temp != NULL)
        {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    E removeAny()
    { // Delete min value
        if (root != NULL)
        {
            E temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else
            return NULL;
    }
    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    E find(const Key &k) const { return findhelp(root, k); }
    // Return the number of records in the dictionary.
    int size() { return nodecount; }
    void print() const
    { // Print the contents of the BinTree
        if (root == NULL)
            cout << "The BinTree is empty";
        else
            printhelp(root);
        cout << endl;
    }
    void inorder() const
    {
        if (root == NULL)
            cout << "The BinTree is empty";
        else
            root->inorder();
        cout << endl;
    }
    void preorder() const
    {
        if (root == NULL)
            cout << "The BinTree is empty";
        else
            root->preorder();
        cout << endl;
    }
    void postorder() const
    {
        if (root == NULL)
            cout << "The BinTree is empty";
        else
            root->postorder();
        cout << endl;
    }
};
template <typename Key, typename E>
E BinTree<Key, E>::findhelp(BSTNode<Key, E> *root, const Key &k) const
{
    if (root == NULL)
        return NULL; // Empty tree
    if (k < root->key())
        return findhelp(root->left(), k); // Check left
    else if (k > root->key())
        return findhelp(root->right(), k); // Check right
    else
        return root->element(); // Found it
}
template <typename Key, typename E>
BSTNode<Key, E> *BinTree<Key, E>::inserthelp(BSTNode<Key, E> *root, const Key &k, const E &it)
{
    if (root == NULL) // Empty tree: create node
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    if (k < root->key())
        root->setLeft(inserthelp(root->left(), k, it));
    else
        root->setRight(inserthelp(root->right(), k, it));
    return root; // Return tree with node inserted
}
template <typename Key, typename E>
BSTNode<Key, E> *BinTree<Key, E>::deletemin(BSTNode<Key, E> *root)
{
    if (root->left() == NULL) // Found min
        return root->right();
    else
    { // Continue left
        root->setLeft(deletemin(root->left()));
        return root;
    }
}
template <typename Key, typename E>
BSTNode<Key, E> *BinTree<Key, E>::getmin(BSTNode<Key, E> *root)
{
    if (root->left() == NULL)
        return root;
    else
        return getmin(root->left());
}
// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E> *BinTree<Key, E>::removehelp(BSTNode<Key, E> *root, const Key &k)
{
    if (root == NULL)
        return NULL; // k is not in tree
    else if (k < root->key())
        root->setLeft(removehelp(root->left(), k));
    else if (k > root->key())
        root->setRight(removehelp(root->right(), k));
    else
    { // Found: remove it
        BSTNode<Key, E> *temp = root;
        if (root->left() == NULL)
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
        { // Both children are non-empty
            BSTNode<Key, E> *temp = getmin(root->right());
            root->setElement(temp->element());
            root->setKey(temp->key());
            root->setRight(deletemin(root->right()));
            delete temp;
        }
    }
    return root;
}
template <typename Key, typename E>
void BinTree<Key, E>::clearhelp(BSTNode<Key, E> *root)
{
    if (root == NULL)
        return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}
template <typename Key, typename E>
void BinTree<Key, E>::printhelp(BSTNode<Key, E> *root) const
{
    if (root == NULL)
        return;          // Empty tree
    cout << root->key(); // Print node value
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
