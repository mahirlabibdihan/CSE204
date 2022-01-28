// In worst case, this implementation works for approximately 40000 unique elements.
#ifndef __QUICK_SORT__
#define __QUICK_SORT__

template <typename E, typename Comp>
class QuickSort
{
    static E *A;
    static int (*findPivot)(int, int);
    static int partition(int left, int right, E &pivot)
    {
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (Comp::prior(A[j], pivot))
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        // <pivot  --- pivot --- >=pivot
        return i + 1; // Return first position in right partition
    }
    static void sort(int left, int right)
    { // Quicksort
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
            sort(left, k - 1);
        }
        if (k + 1 < right) // Tail call optimization
        {
            sort(k + 1, right);
        }
    }

public:
    QuickSort(E *A, int left, int right, int (*findPivot)(int, int))
    {
        QuickSort::A = A;
        QuickSort::findPivot = findPivot;
        sort(left, right);
    }
};
template <typename E, typename Comp>
E *QuickSort<E, Comp>::A;
template <typename E, typename Comp>
int (*QuickSort<E, Comp>::findPivot)(int, int);
#endif