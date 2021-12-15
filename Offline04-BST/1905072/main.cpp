#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "BST.hpp"

int main()
{
    BST<int, int> *bst = new BST<int, int>();
    ifstream in("input.txt");
    while (!in.eof())
    {
        char c;
        int n;
        string s;
        in >> c;
        switch (c)
        {
        case 'I': // Insert
        {
            in >> n;
            bst->insert(n, n);
            cout << bst << endl;
            break;
        }
        case 'F': // Find
        {
            in >> n;
            if (bst->find(n))
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        }
        case 'D': // Delete
        {
            in >> n;
            if (bst->remove(n))
                cout << bst << endl;
            else
                cout << "Invalid Operation" << endl;
            break;
        }
        case 'T': // Traverse
        {
            in >> s;
            int *arr;
            if (s == "In")
                arr = bst->inorder();
            else if (s == "Pre")
                arr = bst->preorder();
            else if (s == "Post")
                arr = bst->postorder();
            for (int i = 0; i < bst->size(); i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            delete[] arr;
            break;
        }
        default:
            break;
        }
    }
    delete bst;
}