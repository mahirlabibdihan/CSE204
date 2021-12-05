#include <iostream>
#include "AStack.hpp"
#include "LStack.hpp"
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

    int a[x];
    // Time needed to wash ith dish
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    // Stack for dishes
    Dish *arr = new Dish[n * x];
    Stack<Dish> *dirty = new AStack<Dish>(arr, 1, n * x), *clean = new AStack<Dish>(arr, -1, n * x); // 2 stack 1 array
    // Stack<Dish> *dirty = new AStack<Dish>(), *clean = new AStack<Dish>();    // Array implementation
    // Stack<Dish> *dirty = new LStack<Dish>(), *clean = new LStack<Dish>(); // LL implementation

    // Friends who have taken full meal
    Stack<int> *fullMeal = new AStack<int>();

    while (true)
    {
        int k, t, s;
        cin >> k >> t >> s;

        if (k == 0)
        {
            break;
        }
        if (s == x)
        {
            fullMeal->push(k);
        }
        while (dirty->length() > 0)
        {
            Dish tmp = dirty->topValue();

            // Calculating end time
            if (clean->length() == 0)
            {
                tmp.t = dirty->topValue().t - 1 + a[dirty->topValue().s - 1];
            }
            else if (t > clean->topValue().t)
            {
                if (dirty->topValue().t > clean->topValue().t)
                {
                    tmp.t = dirty->topValue().t - 1 + a[dirty->topValue().s - 1];
                }
                else
                {
                    tmp.t = clean->topValue().t + a[dirty->topValue().s - 1];
                }
            }
            else
            {
                break;
            }

            // Moving dish from dirty to clean
            dirty->pop();
            clean->push(tmp);
        }
        dirty->push({k, t, s}); // Pushing new dish to dirty stack
    }

    // Move rest of the dishes from dirty to clean
    while (dirty->length() > 0)
    {
        Dish tmp = dirty->topValue();

        // Calculating end time
        if (clean->length() == 0)
        {
            tmp.t = dirty->topValue().t - 1 + a[dirty->topValue().s - 1];
        }
        else
        {
            if (dirty->topValue().t > clean->topValue().t)
            {
                tmp.t = dirty->topValue().t - 1 + a[dirty->topValue().s - 1];
            }
            else
            {
                tmp.t = clean->topValue().t + a[dirty->topValue().s - 1];
            }
        }
        // Moving dish from dirty to clean
        dirty->pop();
        clean->push(tmp);
    }

    // Total time
    cout << clean->topValue().t << endl; // Pushing new plate to dirty stack

    // Dish washed excution time
    Stack<int> *tmp = new AStack<int>(clean->length());
    while (clean->length() > 0)
    {
        tmp->push(clean->topValue().t);
        clean->pop();
    }
    while (tmp->length() > 0)
    {
        cout << tmp->topValue();
        tmp->pop();
        if (tmp->length() > 0)
        {
            cout << ",";
        }
    }
    cout << endl;
    // All Fullmeal or not
    cout << (fullMeal->length() == n ? 'Y' : 'N') << endl;

    // Id of friends with full meal in reverse chronological order
    while (fullMeal->length() > 0)
    {
        cout << fullMeal->topValue();
        fullMeal->pop();
        if (fullMeal->length() > 0)
        {
            cout << ",";
        }
    }
    cout << endl;
}

/*
Test Case 1:
Input:
3 3
2 4 1
1 0 1
3 1 1
2 5 1
1 7 2
3 8 2
3 10 3
0 0 0
Output:
15
1, 3, 6, 10, 11, 15
N
3
Test Case 2:
Input:
3 3
2 4 1
1 0 1
3 1 1
2 5 1
1 7 2
3 8 2
3 10 3
1 17 3
0 0 0
Output:
17
1,3,6,10,11,15,17
N
1,3
*/