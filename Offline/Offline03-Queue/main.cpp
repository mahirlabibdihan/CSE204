#include "LDeque.hpp"
#include "ADeque.hpp"
template <typename E>
ostream &operator<<(ostream &os, Deque<E> *q)
{
    os << "<";
    for (int i = 0; i < q->length(); i++)
    {
        E tmp = q->pop_front();
        os << tmp;
        if (i < q->length())
        {
            os << ", ";
        }
        q->push_back(tmp);
    }
    os << ">";
    return os;
}

int main()
{
    int k;
    cin >> k;
    Deque<int> *q = new LDeque<int>(k);
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        q->push_back(tmp);
    }

    cout << q << endl;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            break;
        }
        int tmp;
        switch (a)
        {
        case 1: // clear()
            q->clear();
            cout << q << endl;
            cout << -1 << endl;
            break;
        case 2: // enqueue(item)
            q->push_front(b);
            cout << q << endl;
            cout << -1 << endl;
            break;
        case 3: // dequeue
            tmp = q->pop_back();
            cout << q << endl;
            cout << tmp << endl;
            break;
        case 4: // length
            cout << q << endl;
            cout << q->length() << endl;
            break;
        case 5: // frontValue
            cout << q << endl;
            cout << q->front() << endl;
            break;
        case 6: // rearValue
            cout << q << endl;
            cout << q->back() << endl;
            break;
        case 7: // leaveQueue
            tmp = q->pop_back();
            cout << q << endl;
            cout << tmp << endl;
            break;
        default: // exit
            return 0;
            break;
        }
    }
    delete q;
}
/*
5
1 2 3 4 5
7 0
*/