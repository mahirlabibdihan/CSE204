#include <iostream>
#include "AStack.hpp"
using namespace std;

// Structure for dishes
struct Dish
{
    int k, t, s;
};
int main()
{
    int n, x;
    cin >> n >> x;

    int a[n];
    // Time needed to wash ith dish
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    // Stack for dishes
    Stack<Dish> *dirty = new AStack<Dish>(), *clean = new AStack<Dish>();

    // Friends who have taken full meal
    Stack<int> *fullMeal = new AStack<int>();

    // Count of courses taken by ith friend
    int courseCount[n] = {};
    while (true)
    {
        int k, t, s;
        cin >> k >> t >> s;
        if (k == 0)
        {
            break;
        }
        courseCount[k - 1]++;
        if (courseCount[k - 1] == x)
        {
            fullMeal->push(k);
        }
        while (dirty->length() > 0)
        {
            if (clean->length() == 0)
            {
                clean->push({dirty->topValue().k, dirty->topValue().t + a[dirty->topValue().s - 1], dirty->topValue().s});
                dirty->pop();
            }
            else if (t > clean->topValue().t)
            {
                clean->push({dirty->topValue().k, clean->topValue().t + a[dirty->topValue().s - 1], dirty->topValue().s});
                dirty->pop();
            }
            else
            {
                break;
            }
        }
        dirty->push({k, t, s});
    }
    while (dirty->length() > 0)
    {
        if (clean->length() == 0)
        {
            clean->push({dirty->topValue().k, dirty->topValue().t + a[dirty->topValue().s - 1], dirty->topValue().s});
            dirty->pop();
        }
        else
        {
            clean->push({dirty->topValue().k, clean->topValue().t + a[dirty->topValue().s - 1], dirty->topValue().s});
            dirty->pop();
        }
    }

    /*cout << "<";
    while (clean->length() > 0)
    {
        cout << clean->topValue().k << " " << clean->topValue().t << " " << clean->topValue().s << endl;
        clean->pop();
    }
    cout << ">" << endl;*/

    // Total time
    cout << clean->topValue().t << endl;

    // Dish washed no
    Stack<int> *tmp = new AStack<int>(clean->length());
    cout << "<";
    while (clean->length() > 0)
    {
        tmp->push(clean->topValue().s);
        clean->pop();
    }
    while (tmp->length() > 0)
    {
        cout << tmp->topValue();
        if (tmp->length() > 0)
        {
            cout << ", ";
        }
        tmp->pop();
    }
    cout << ">" << endl;

    // All Fullmeal or not
    cout << (fullMeal->length() == n ? 'Y' : 'N') << endl;   

    // Id of friends with full meal in reverse chronological order
    cout << "<";
    while (clean->length() > 0)
    {
        cout << fullMeal->topValue();
        if (fullMeal->length() > 0)
        {
            cout << ", ";
        }
        clean->pop();
    }
    cout << ">" << endl;
}