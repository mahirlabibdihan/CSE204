#ifndef __MERGE_SORT__
#define __MERGE_SORT__
#include <iostream>
using namespace std;
namespace Comparators
{
    template <typename E>
    bool less(const E &a, const E &b)
    {
        return a < b;
    }
    template <typename E>
    bool greater(const E &a, const E &b)
    {
        return a > b;
    }
};
namespace MergeSort
{
    template <typename E>
    bool (*comp)(const E &, const E &);
    template <typename E>
    E *A;
    template <typename E>
    void merge(int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = 0;
        E *mergedArray = new E[right - left + 1];
        // Merging left and right sub-Array in a temporary Array in sorted order.
        while (i <= mid && j <= right)
        {
            if (comp<E>(A<E>[i], A<E>[j]))
            {
                mergedArray[k++] = A<E>[i++];
            }
            else
            {
                mergedArray[k++] = A<E>[j++];
            }
        }
        while (j <= right)
        {
            mergedArray[k++] = A<E>[j++];
        }
        while (i <= mid)
        {
            mergedArray[k++] = A<E>[i++];
        }
        // Copying the temporary Array back to Original Array
        for (i = left; i <= right; i++)
        {
            A<E>[i] = mergedArray[i - left];
        }
        delete[] mergedArray;
    }
    template <typename E>
    void divide(int left, int right)
    {
        if (left >= right)
        {
            return; // List of one/zero element
        }
        int mid = left + (right - left) / 2;
        if (left < mid) // Tail call optimization
        {
            divide<E>(left, mid);
        }
        if (mid + 1 < right) // Tail call optimization
        {
            divide<E>(mid + 1, right);
        }
        merge<E>(left, mid, right);
    }
    template <typename E>
    void sort(E *begin, E *end, bool (*comp)(const E &, const E &) = Comparators::less<E>)
    {
        MergeSort::comp<E> = comp;
        MergeSort::A<E> = begin;
        divide<E>(begin - begin, end - begin);
    }
};
#endif