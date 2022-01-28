#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__
#include <iostream>
#include "Comparators.hpp"
using namespace std;
template <typename E, typename Comp = std::less<E>>
class InsertionSort
{
public:
    static void sort(E *A, int left, int right, Comp comp = Comp())
    {
        for (int i = left + 1; i <= right; i++)
        {
            // Taking one element from unsorted part, and inserting it to sorted part.
            for (int j = i; j > left && comp(A[j], A[j - 1]); j--)
            {
                swap(A[j], A[j - 1]);
            }
        }
    }
};
#endif