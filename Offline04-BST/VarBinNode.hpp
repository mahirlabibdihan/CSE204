// Node implementation with simple inheritance
class VarBinNode
{ // Node abstract base class
public:
    virtual ~VarBinNode() {}
    virtual bool isLeaf() = 0; // Subclasses must implement
    virtual void traverse() = 0;
};