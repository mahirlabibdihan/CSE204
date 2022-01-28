#include <iostream>
#include "DLList.hpp"
#include "SLList.hpp"
#include "AList.hpp"
using namespace std;

void encode(List<int> *lst, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (lst->search(i) > -1)
        {
            cout << i;
        }
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> k;
    int r[k];
    for (int i = 0; i < k; i++)
    {
        r[i] = i;
    }

    int l;
    cin >> l;
    int b[l];
    for (int i = 0; i < l; i++)
    {
        cin >> b[i];
    }

    int m;
    cin >> m;
    int t[m];
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }

    List<int> *rick = new AList<int>(r, k, k);
    List<int> *bus = new AList<int>(b, l, k);
    List<int> *train = new AList<int>(t, m, k);
    int q;
    cin >> q;
    switch (q)
    {
    case 1:
        encode(rick, k);
        encode(bus, k);
        encode(train, k);
        break;

    default:
        break;
    }
}
/*
15
7
0 2 5 6 9 11 14
4
0 5 11 14
1
*/