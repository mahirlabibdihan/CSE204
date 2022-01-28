#ifndef __MERGE_SORT__
#define __MERGE_SORT__
template <typename E, typename Comp = std::less<E>>
class MergeSort
{
    static E *A;
    static Comp comp;
    static void merge(int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = 0;
        E *mergedArray = new E[right - left + 1];
        // Merging left and right sub-Array in a temporary Array in sorted order.
        while (i <= mid && j <= right)
        {
            if (comp(A[i], A[j]))
            {
                mergedArray[k++] = A[i++];
            }
            else
            {
                mergedArray[k++] = A[j++];
            }
        }
        while (j <= right)
        {
            mergedArray[k++] = A[j++];
        }
        while (i <= mid)
        {
            mergedArray[k++] = A[i++];
        }
        // Copying the temporary Array back to Original Array
        for (i = left; i <= right; i++)
        {
            A[i] = mergedArray[i - left];
        }
        delete[] mergedArray;
    }
    static void divide(int left, int right)
    {
        if (left >= right)
        {
            return; // List of one/zero element
        }
        int mid = left + (right - left) / 2;
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

public:
    static void sort(E *A, int left, int right, Comp comp = Comp())
    {
        MergeSort::A = A;
        MergeSort::comp = comp;
        divide(left, right);
    }
};
template <typename E, typename Comp>
E *MergeSort<E, Comp>::A;
template <typename E, typename Comp>
Comp MergeSort<E, Comp>::comp;
#endif