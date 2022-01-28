#ifndef __MERGE_SORT__
#define __MERGE_SORT__
#include "Comparators.hpp"
#include <iostream>
using namespace std;

namespace MergeSort
{
    template <typename E>
    bool (*comp)(const E &a, const E &b);
    template <typename E>
    void merge(E *left, E *mid, E *right)
    {
        E *mergedArray = new E[right - left + 1];
        E *i = left, *j = mid + 1, *k = mergedArray;
        // Merging left and right sub-Array in a temporary Array in sorted order.
        while (i != mid + 1 && j != right + 1)
        {
            if (comp<E>(*i, *j))
            {
                *k = *i;
                k++, i++;
            }
            else
            {
                *k = *j;
                k++, j++;
            }
        }
        while (j != right + 1)
        {
            *k = *j;
            k++, j++;
        }
        while (i != mid + 1)
        {
            *k = *i;
            k++, i++;
        }
        // Copying the temporary Array back to Original Array
        for (i = left, k = mergedArray; i != right + 1; i++, k++)
        {
            *i = *k;
        }
        delete[] mergedArray;
    }
    template <typename E>
    void divide(E *left, E *right)
    {
        // cout << right - left << endl;
        if (left >= right)
        {
            return; // List of one/zero element
        }
        E *mid = left + (right - left) / 2;
        if (left < mid) // Tail call optimization
        {
            divide(left, mid);
        }
        if (mid + 1 < right) // Tail call optimization
        {
            divide(mid + 1, right);
        }
        merge(left, mid, right);
    }
    template <typename E>
    void sort(E *begin, E *end, bool (*comp)(const E &a, const E &b) = Comparators::less<E>)
    {
        MergeSort::comp<E> = comp;
        divide(begin, end - 1);
    }
};
#endif