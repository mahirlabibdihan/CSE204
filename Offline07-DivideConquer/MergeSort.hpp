#ifndef __MERGE_SORT__
#define __MERGE_SORT__
template <typename E, typename Comp>
class MergeSort
{
    static E *A;
    static void merge(int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = 0;
        E *mergedArray = new E[right - left + 1];
        // Merging left and right sub-Array in a temporary Array in sorted order.
        while (i <= mid && j <= right)
        {
            if (Comp::prior(A[i], A[j]))
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
    static void sort(int left, int right)
    {
        if (left >= right)
        {
            return; // List of one/zero element
        }
        int mid = left + (right - left) / 2;
        if (left < mid) // Tail call optimization
        {
            sort(left, mid);
        }
        if (mid + 1 < right) // Tail call optimization
        {
            sort(mid + 1, right);
        }
        merge(left, mid, right);
    }

public:
    MergeSort(E *A, int left, int right)
    {
        MergeSort::A = A;
        sort(left, right);
    }
};
template <typename E, typename Comp>
E *MergeSort<E, Comp>::A;
#endif