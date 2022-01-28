#include <iostream>
#include <algorithm>
#include <chrono>
#include <type_traits>
#include <cstdlib>
using namespace std;

namespace Merge
{
    template <class Comp>
    Comp comp;
    template <typename E, typename Comp>
    void merge(E left, E mid, E right)
    {
        E mergedArray = new typename remove_pointer<E>::type[right - left];
        E i = left, j = mid, k = mergedArray;
        // Merging left and right sub-Array in a temporary Array in sorted order.
        while (i != mid && j != right)
        {
            if (comp<Comp>(*i, *j))
            {
                *k++ = *i++;
            }
            else
            {
                *k++ = *j++;
            }
        }
        while (j != right)
        {
            *k++ = *j++;
        }
        while (i != mid)
        {
            *k++ = *i++;
        }
        // Copying the temporary Array back to Original Array
        for (i = left, k = mergedArray; i != right;)
        {
            *i++ = *k++;
        }
    }
    template <typename E, typename Comp>
    void divide(E begin, E end)
    {
        if (begin + 1 >= end)
        {
            return; // List of one/zero element
        }
        E mid = begin + (end - begin) / 2;
        divide<E, Comp>(begin, mid);
        divide<E, Comp>(mid, end);
        merge<E, Comp>(begin, mid, end);
    }

    template <typename E, typename Comp>
    void sort(E begin, E end, Comp comp)
    {
        Merge::comp<Comp> = comp;
        divide<E, Comp>(begin, end);
    }
}
namespace Quick
{
    enum Mode
    {
        LAST_PIVOT,
        FIRST_PIVOT,
        MID_PIVOT,
        RANDOM_PIVOT
    } pivotMode;
    template <class Comp>
    Comp comp;
    template <class E>
    E findPivot(E left, E right)
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
    template <typename E, typename Comp>
    E partition(E begin, E end)
    {
        E pivotIdx = findPivot(begin, end);
        if (pivotIdx != end)
        {
            swap(*pivotIdx, *begin); // Put pivot at end
        }
        E i = begin - 1;
        for (E j = begin; j < end; j++)
        {
            if (comp<Comp>(*j, *end))
            {
                i++;
                swap(*i, *j);
            }
        }
        i++;
        if (i != end)
        {
            swap(*i, *end); // Put pivot in place
        }
        // <pivot  --- pivot --- >=pivot
        return i; // Return first position in right partition
    }

    template <class E, class Comp>
    void divide(E left, E right)
    {
        if (right <= left)
        {
            return; // Don’t sort 0 or 1 element
        }
        // k will be the first position in the right subarray
        E k = Quick::partition<E, Comp>(left, right);
        divide<E, Comp>(left, k - 1);
        divide<E, Comp>(k + 1, right);
    }
    template <class E, class Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        Quick::comp<Comp> = comp;
        Quick::pivotMode = LAST_PIVOT;
        divide<E, Comp>(begin, end - 1);
    }
    template <class E, class Comp>
    void rsort(const E begin, const E end, Comp comp)
    {
        Quick::comp<Comp> = comp;
        Quick::pivotMode = RANDOM_PIVOT;
        divide<E, Comp>(begin, end - 1);
    }
}
namespace Insertion
{
    template <class E, class Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        for (E i = begin + 1; i != end; i++)
        {
            // Taking one element from unsorted part, and inserting it to sorted part.
            for (E j = i; j != begin && comp(*j, *(j - 1)); j--)
            {
                swap(*j, *(j - 1));
            }
        }
    }
}
template <class E, class Comp>
double allSort(E arr1, E arr2, int n, void (*mySort)(const E, const E, Comp), bool isSorted = false, int totalTest = 20)
{
    double avg = 0;
    for (int i = 0; i < totalTest; i++)
    {
        if (!isSorted)
        {
            std::copy(arr1, arr1 + n, arr2);
        }
        clock_t startTime = clock();
        mySort(arr2, arr2 + n, Comp());
        clock_t endTime = clock();
        avg += endTime - startTime;
    }
    return avg / totalTest;
}
void generateArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
int main()
{
    // freopen("output.csv", "w", stdout);
    srand(1905072);
    const int n[] = {5, 10, 100, 1000, 10000, 100000};
    cout << "Time,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with sorted input,Randomized Quicksort with sorted input,STL sort() function" << endl;
    for (int j = 0; j < sizeof(n) / sizeof(n[0]); j++)
    {
        const int N = n[j];
        cout << N << ",";
        int *mainArray = new int[N];
        generateArray(mainArray, N);
        int *tempArray = new int[N];
        cout << allSort(mainArray, tempArray, N, Merge::sort<int *, less<int>>) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        for(int i=0;i<N;i++)
        {
            
        }
        // cout << allSort(mainArray, tempArray, N, Quick::sort<int *, less<int>>) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        // cout << allSort(mainArray, tempArray, N, Quick::rsort<int *, less<int>>) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        // cout << allSort(mainArray, tempArray, N, Insertion::sort<int *, less<int>>) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        // cout << allSort(mainArray, tempArray, N, Quick::sort<int *, less<int>>, true) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << allSort(mainArray, tempArray, N, Quick::rsort<int *, less<int>>, true) << ',' << '(' << is_sorted(tempArray, tempArray + N) << ')';
        // cout << allSort(mainArray, tempArray, N, std::sort<int *, less<int>>) << endl;
        delete[] mainArray, tempArray;
    }
    return 0;
}