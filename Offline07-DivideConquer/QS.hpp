// In worst case, this implementation works for approximately 40000 unique elements.
#ifndef __QUICK_SORT__
#define __QUICK_SORT__
#include <iostream>
using namespace std;
namespace QuickSort
{
    enum Mode
    {
        LAST_PIVOT,
        FIRST_PIVOT,
        MID_PIVOT,
        RANDOM_PIVOT
    };
    Mode pivotMode;

    template <typename E>
    bool (*comp)(const E &a, const E &b);

    template <typename E>
    E *partition(E *left, E *right, E &pivot)
    {
        E *i = left - 1;
        for (E *j = left; j != right; j++)
        {
            if (comp<E>(*j, pivot))
            {
                i++;
                swap(*i, *j);
            }
        }
        return i + 1; // Return first position in right partition
    }
    template <typename E>
    E *findPivot(E *left, E *right)
    {
        if (pivotMode == LAST_PIVOT)
        {
            return right;
        }
        else if (pivotMode == FIRST_PIVOT)
        {
            return left;
        }
        else if (pivotMode == MID_PIVOT)
        {
            return left + (right - left) / 2;
        }
        else
        {
            return left + (rand() % (right - left + 1));
        }
    }
    template <typename E>
    void qSort(E *left, E *right)
    { // Quicksort
        if (right <= left)
        {
            return; // Don’t sort 0 or 1 element
        }
        E *pivot = findPivot(left, right);
        if (pivot != right)
        {
            swap(*pivot, *right); // Put pivot at end
        }
        // k will be the first position in the right subarray
        E *k = partition(left, right, *right);
        if (k != right)
        {
            swap(*k, *right); // Put pivot in place
        }
        if (left < k - 1) // Tail call optimization
        {
            qSort(left, k - 1);
        }
        if (k + 1 < right) // Tail call optimization
        {
            qSort(k + 1, right);
        }
    }

    template <typename E>
    void sort(E *begin, E *end, bool (*comp)(const E &a, const E &b) = Comparators::less<E>)
    {
        QuickSort::pivotMode = LAST_PIVOT;
        qSort(begin, end-1);
    }

    template <typename E>
    void randomizedSort(E *begin, E *end, bool (*comp)(const E &a, const E &b) = Comparators::less<E>)
    {
        QuickSort::pivotMode = LAST_PIVOT;
        qSort(begin, end - 1);
    }
};
#endif