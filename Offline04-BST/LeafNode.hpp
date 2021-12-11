#include "VarBinNode.hpp"
#include <iostream>
using namespace std;
class LeafNode : public VarBinNode
{ // Leaf node
private:
    Operand var; // Operand value
public:
    LeafNode(const Operand &val) { var = val; } // Constructor
    bool isLeaf() { return true; }              // Version for LeafNode
    Operand value() { return var; }             // Return node value
    void traverse() { cout << "Leaf: " << value() << endl; }
};