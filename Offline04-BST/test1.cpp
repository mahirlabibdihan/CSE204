#include <iostream>
using namespace std;
#include "BST.hpp"
int main()
{
    BST<int, int> bst;
    bst.insert(10, 10);
    bst.insert(17, 17);
    bst.insert(1, 1);
    bst.insert(4, 4);
    bst.insert(8, 8);
    while (bst.size() > 0)
    {
        cout << bst.removeAny() << " ";
    }
}