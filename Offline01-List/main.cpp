#include "AList.hpp"
#include "LList.hpp"
template <typename T>
void print(List<T> *lst)
{
    int curr = lst->currPos();
    cout << "<";
    if (lst->length() > 0)
    {
        for (lst->moveToStart();;)
        {
            if (lst->currPos() == curr)
            {
                cout << "| ";
            }
            cout << lst->getValue() << ' ';

            if (lst->currPos() + 1 < lst->length())
            {
                lst->next();
            }
            else
            {
                break;
            }
        }
        lst->moveToPos(curr);
    }
    cout << ">" << endl;
}

int main()
{
    int k, x;
    cin >> k >> x;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    List<int> *lst = new LList<int>(a, k, x);
    print(lst);
    while (true)
    {
        int p, q;
        cin >> q >> p;
        if (q == 0)
        {
            break;
        }
        int tmp;
        switch (q)
        {
        case 1: // clear()
            lst->clear();
            print(lst);
            cout << -1 << endl;
            break;
        case 2: // insert(item)
            lst->insert(p);
            print(lst);
            cout << -1 << endl;
            break;
        case 3: // append
            lst->append(p);
            print(lst);
            cout << -1 << endl;
            break;
        case 4: // remove
            tmp = lst->remove();
            print(lst);
            cout << tmp << endl;
            break;
        case 5: // moveToStart
            lst->moveToStart();
            print(lst);
            cout << -1 << endl;
            break;
        case 6: // moveToEnd
            lst->moveToEnd();
            print(lst);
            cout << -1 << endl;
            break;
        case 7: // prev
            lst->prev();
            print(lst);
            cout << -1 << endl;
            break;
        case 8: // next
            lst->next();
            print(lst);
            cout << -1 << endl;
            break;
        case 9: // length
            print(lst);
            cout << lst->length() << endl;
            break;
        case 10: // currPos
            print(lst);
            cout << lst->currPos() << endl;
            break;
        case 11: // moveToPos
            lst->moveToPos(p);
            print(lst);
            cout << -1 << endl;
            break;
        case 12: // getValue
            print(lst);
            cout << lst->getValue() << endl;
            break;
        case 13: // search
            print(lst);
            cout << lst->Search(p) << endl;
            break;
        default: // exit
            return 0;
            break;
        }
    }
    delete lst;
}
/*
5 10
10 12 34 9 1
11 3
4 0
7 0
2 20
9 0
6 0
3 99
8 0
5 0
13 12
12 0
10 0
1 0
0 0
*/
