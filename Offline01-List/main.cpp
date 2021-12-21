#include "SLList.hpp"
#include "DLList.hpp"
template <typename E>
ostream &operator<<(ostream &os, List<E> *lst)
{
    int curr = lst->currPos();
    os << "<";
    if (lst->length() > 0)
    {
        for (lst->moveToStart();; lst->next())
        {
            if (lst->currPos() == curr)
            {
                os << "| ";
            }
            os << lst->getValue() << ' ';

            if (lst->currPos() + 1 == lst->length())
            {
                break;
            }
        }
        lst->moveToPos(curr);
    }
    os << ">";
    return os;
}

int main()
{
    int k, x;
    cin >> k >> x;
    List<int> *lst = new DLList<int>(x);
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        lst->append(a);
    }

    cout << lst << endl;
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
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 2: // insert(item)
            lst->insert(p);
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 3: // append
            lst->append(p);
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 4: // remove
            tmp = lst->remove();
            cout << lst << endl;
            cout << tmp << endl;
            break;
        case 5: // moveToStart
            lst->moveToStart();
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 6: // moveToEnd
            lst->moveToEnd();
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 7: // prev
            lst->prev();
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 8: // next
            lst->next();
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 9: // length
            cout << lst << endl;
            cout << lst->length() << endl;
            break;
        case 10: // currPos
            cout << lst << endl;
            cout << lst->currPos() << endl;
            break;
        case 11: // moveToPos
            lst->moveToPos(p);
            cout << lst << endl;
            cout << -1 << endl;
            break;
        case 12: // getValue
            cout << lst << endl;
            cout << lst->getValue() << endl;
            break;
        case 13: // search
            cout << lst << endl;
            cout << lst->search(p) << endl;
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
