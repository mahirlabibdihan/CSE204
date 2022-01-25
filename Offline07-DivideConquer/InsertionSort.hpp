#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__
#include <iostream>
using namespace std;
template <typename E, typename Comp>
void iSort(E *begin, E *end)
{
    for (E *i = begin + 1; i != end; i++)
    {
        // Taking one element from unsorted part, and inserting it to sorted part.
        for (E *j = i; j != begin && Comp::prior(*j, *(j - 1)); j--)
        {
            swap(*j, *(j - 1));
        }
    }
}
#endif