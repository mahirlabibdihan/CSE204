#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
using namespace std;
#define STL_SORT sort(arr2, arr2 + n)
#define MERGE_SORT MergeSort<int, Comp>(arr2, 0, n - 1)
#define INSERTION_SORT iSort<int, Comp>(arr2, arr2 + n)
#define QUICK_SORT QuickSort<int, Comp>(arr2, 0, n - 1, getLast)
#define RANDOM_QUICK_SORT QuickSort<int, Comp>(arr2, 0, n - 1, getRandom)
#define SORT_TIME(arr1, arr2, n, isSorted, __SORT_STATEMENT__) \
    double avg = 0;                                            \
    for (int i = 0; i < 20; i++)                               \
    {                                                          \
        if (!isSorted)                                         \
        {                                                      \
            copyArray(arr1, arr2, n);                          \
        }                                                      \
        clock_t startTime = clock();                           \
        __SORT_STATEMENT__;                                    \
        clock_t endTime = clock();                             \
        avg += endTime - startTime;                            \
    }                                                          \
    return avg / 20;
/*
1. Generate an array.
2. Sort that array using Insertion/Merge/Quick/Randomized Quick
3. Sort the sorted array again using Quick/Randomized Quick/STL
*/
class Comp
{
public:
    static bool prior(const int &a, const int &b)
    {
        return a < b;
    }
};
// The function will choose the pivot index
int getLast(int left, int right)
{
    return right;
}
// The function will choose the pivot index
int getRandom(int left, int right)
{
    return (rand() % (right - left + 1)) + left;
}
void generateArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
void copyArray(int *arr1, int *arr2, int n)
{
    for (int j = 0; j < n; j++)
    {
        arr2[j] = arr1[j];
    }
}
double getMergeSortTime(int *arr1, int *arr2, int n, bool isSorted = false)
{
    SORT_TIME(arr1, arr2, n, isSorted, MERGE_SORT);
}
double getQuickSortTime(int *arr1, int *arr2, int n, bool isSorted = false)
{
    SORT_TIME(arr1, arr2, n, isSorted, QUICK_SORT);
}
double getRandomizedQuickSortTime(int *arr1, int *arr2, int n, bool isSorted = false)
{
    SORT_TIME(arr1, arr2, n, isSorted, RANDOM_QUICK_SORT);
}
double getInsertionSortTime(int *arr1, int *arr2, int n, bool isSorted = false)
{
    SORT_TIME(arr1, arr2, n, isSorted, INSERTION_SORT);
}
double getSTLSortTime(int *arr1, int *arr2, int n, bool isSorted = false)
{
    SORT_TIME(arr1, arr2, n, isSorted, STL_SORT);
}
int main()
{
    // freopen("output.csv", "w", stdout);
    srand(1905072);
    int n[] = {5, 10, 100, 1000, 10000, 100000};
    cout << "Time,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with sorted input,Randomized Quicksort with sorted input,STL sort() function" << endl;
    for (int j = 0; j < sizeof(n) / sizeof(n[0]); j++)
    {
        int N = n[j];
        cout << N << ",";
        int *arr1 = new int[N];
        generateArray(arr1, N);
        int *arr2 = new int[N];
        cout << getMergeSortTime(arr1, arr2, N) << ',';
        cout << getQuickSortTime(arr1, arr2, N) << ',';
        cout << getRandomizedQuickSortTime(arr1, arr2, N) << ',';
        cout << getInsertionSortTime(arr1, arr2, N) << ',';
        cout << getQuickSortTime(arr1, arr2, N, true) << ',';
        cout << getRandomizedQuickSortTime(arr1, arr2, N, true) << ',';
        cout << getSTLSortTime(arr1, arr2, N) << endl;
        delete[] arr1, arr2;
    }
    return 0;
}