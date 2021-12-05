#include "LStack.hpp"
template <typename T>
void print(Stack<T> *s)
{
    Stack<T> *tmp = new LStack<T>(s->length());
    cout << s->length() << endl;
    cout << "<";
    while (s->length() > 0)
    {
        tmp->push(s->topValue());
        s->pop();
    }
    while (tmp->length() > 0)
    {
        cout << tmp->topValue();
        s->push(tmp->topValue());
        tmp->pop();
        if (tmp->length() > 0)
        {
            cout << ", ";
        }
    }
    cout << ">" << endl;
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

    print(s);
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
            print(s);
            cout << -1 << endl;
            break;
        case 2: // insert(item)
            s->push(p);
            print(s);
            cout << -1 << endl;
            break;
        case 3: // remove
            tmp = s->pop();
            print(s);
            cout << tmp << endl;
            break;
        case 4: // length
            print(s);
            cout << s->length() << endl;
            break;
        case 5: // getValue
            print(s);
            cout << s->topValue() << endl;
            break;
        case 6: // search
            print(s);
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