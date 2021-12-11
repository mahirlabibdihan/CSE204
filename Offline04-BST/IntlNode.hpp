#include "VarBinNode.hpp"
#include <iostream>
using namespace std;
class IntlNode : public VarBinNode
{ // Internal node
private:
    VarBinNode *left;  // Left child
    VarBinNode *right; // Right child
    Operator opx;      // Operator value
public:
    IntlNode(const Operator &op, VarBinNode *l, VarBinNode *r)
    {
        opx = op;
        left = l;
        right = r;
    }                                          // Constructor
    bool isLeaf() { return false; }            // Version for IntlNode
    VarBinNode *leftchild() { return left; }   // Left child
    VarBinNode *rightchild() { return right; } // Right child
    Operator value() { return opx; }           // Value
    void traverse()
    { // Traversal behavior for internal nodes
        cout << "Internal: " << value() << endl;
        if (left() != NULL)
            left()->traverse();
        if (right() != NULL)
            right()->traverse();
    }
};