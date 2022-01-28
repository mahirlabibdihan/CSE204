#include "LStack.hpp"
template <typename T>
ostream &operator<<(ostream &os, Stack<T> *s)
{
    Stack<T> *tmp = new LStack<T>(s->length());
    os << "<";
    while (s->length() > 0)
    {
        tmp->push(s->topValue());
        s->pop();
    }
    while (tmp->length() > 0)
    {
        os << tmp->topValue();
        s->push(tmp->topValue());
        tmp->pop();
        if (tmp->length() > 0)
        {
            os << ", ";
        }
    }
    cout << ">";
    delete tmp;
    return os;
}

int main()
{
    int k;
    cin >> k;
    Stack<int> *s = new LStack<int>();
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        s->push(a);
    }

    cout << s << endl;
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
            s->clear();
            cout << s << endl;
            cout << -1 << endl;
            break;
        case 2: // insert(item)
            s->push(p);
            cout << s << endl;
            cout << -1 << endl;
            break;
        case 3: // remove
            tmp = s->pop();
            cout << s << endl;
            cout << tmp << endl;
            break;
        case 4: // length
            cout << s << endl;
            cout << s->length() << endl;
            break;
        case 5: // getValue
            cout << s << endl;
            cout << s->topValue() << endl;
            break;
        case 6: // search
            cout << s << endl;
            s->setDirection(p);
            cout << -1 << endl;
            break;
        default: // exit
            return 0;
            break;
        }
    }
    delete s;
}