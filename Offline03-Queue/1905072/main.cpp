#include "LQueue.hpp"
#include "AQueue.hpp"
template <typename T>
ostream &operator<<(ostream &os, Queue<T> *q)
{
    os << "<";
    for (int i = 0; i < q->length(); i++)
    {
        T tmp = q->dequeue();
        os << tmp;
        if (i < q->length())
        {
            os << ", ";
        }
        q->enqueue(tmp);
    }
    os << ">";
    return os;
}

int main()
{
    int k;
    cin >> k;
    Queue<int> *q = new AQueue<int>(k);
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        q->enqueue(tmp);
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
            q->enqueue(b);
            cout << q << endl;
            cout << -1 << endl;
            break;
        case 3: // dequeue
            tmp = q->dequeue();
            cout << q << endl;
            cout << tmp << endl;
            break;
        case 4: // length
            cout << q << endl;
            cout << q->length() << endl;
            break;
        case 5: // frontValue
            cout << q << endl;
            cout << q->frontValue() << endl;
            break;
        case 6: // rearValue
            cout << q << endl;
            cout << q->rearValue() << endl;
            break;
        case 7: // leaveQueue
            tmp = q->leaveQueue();
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