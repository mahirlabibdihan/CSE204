// In worst case, this implementation works for approximately 40000 unique elements. And RAND_MAX = 32767 which is smaller than 40000. So this solution always works when the array is generated randomly
#ifndef __QUICK_SORT__
#define __QUICK_SORT__
#include <iostream>
using namespace std;
template <typename E, typename Comp = std::less<E>>
class QuickSort
{
public:
    enum Mode
    {
        LAST_PIVOT,
        FIRST_PIVOT,
        MID_PIVOT,
        RANDOM_PIVOT
    };

private:
    static E *A;
    static Mode pivotMode;
    static Comp comp;
    static int partition(int left, int right, E &pivot)
    {
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (comp(A[j], pivot))
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        // <pivot  --- pivot --- >=pivot
        return i + 1; // Return first position in right partition
    }
    static int findPivot(int left, int right)
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
            return (rand() % (right - left + 1)) + left;
        }
    }
    static void divide(int left, int right)
    {
        if (right <= left)
        {
            return; // Don’t sort 0 or 1 element
        }
        int pivotIdx = findPivot(left, right);
        if (pivotIdx != right)
        {
            swap(A[pivotIdx], A[right]); // Put pivot at end
        }
        // k will be the first position in the right subarray
        int k = partition(left, right, A[right]);
        if (k != right)
        {
            swap(A[k], A[right]); // Put pivot in place
        }
        if (left < k - 1) // Tail call optimization
        {
            divide(left, k - 1);
        }
        if (k + 1 < right) // Tail call optimization
        {
            divide(k + 1, right);
        }
    }

public:
    static void sort(E *A, int left, int right, Comp comp = Comp())
    {
        QuickSort::A = A;
        QuickSort::comp = comp;
        QuickSort::pivotMode = LAST_PIVOT;
        divide(left, right);
    }
    static void randomizedSort(E *A, int left, int right, Comp comp = Comp())
    {
        QuickSort::A = A;
        QuickSort::comp = comp;
        QuickSort::pivotMode = RANDOM_PIVOT;
        divide(left, right);
    }
};
template <typename E, typename Comp>
E *QuickSort<E, Comp>::A;
template <typename E, typename Comp>
Comp QuickSort<E, Comp>::comp;
template <typename E, typename Comp>
typename QuickSort<E, Comp>::Mode QuickSort<E, Comp>::pivotMode;
#endif