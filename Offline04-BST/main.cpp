#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BST.hpp"
int main()
{
    BinTree<int> *bst = new BST<int>();
    ifstream in("input.txt");
    while (!in.eof())
    {
        char c;
        int n;
        string s;
        in >> c;
        switch (c)
        {
        case 'F':
            in >> n;
            if (bst->find(n) == NULL)
                cout << "False" << endl;
            else
                cout << "True" << endl;
            break;
        case 'I':
            in >> n;
            bst->insert(n);
            bst->print();
            break;
        case 'T':
            in >> s;
            if (s == "In")
                bst->inorder();
            else if (s == "Pre")
                bst->preorder();
            else if (s == "Post")
                bst->postorder();
            break;
        case 'D':
            in >> n;
            if (bst->remove(n) == NULL)
                cout << "Invalid Operation" << endl;
            else
                bst->print();
            break;
        default:
            break;
        }
    }
}