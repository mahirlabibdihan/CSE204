#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
using namespace std;
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

template <typename E>
double getSTLSortTime(E *arr1, E *arr2, int n, bool isSorted = false, int totalTest = 20)
{
    double avg = 0;
    for (int i = 0; i < totalTest; i++)
    {
        if (!isSorted)
        {
            copyArray(arr1, arr2, n);
        }
        clock_t startTime = clock();
        sort(arr2, arr2 + n);
        clock_t endTime = clock();
        avg += endTime - startTime;
    }
    return avg / 20;
}

template <typename E, typename Comp>
double getMySortTime(E *arr1, E *arr2, int n, void (*mySort)(E *, int, int, Comp), bool isSorted = false, int totalTest = 20)
{
    double avg = 0;
    for (int i = 0; i < totalTest; i++)
    {
        if (!isSorted)
        {
            copyArray(arr1, arr2, n);
        }
        clock_t startTime = clock();
        mySort(arr2, 0, n - 1, Comp());
        clock_t endTime = clock();
        avg += endTime - startTime;
    }
    return avg / 20;
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
        int *arr1 = new int[N];
        generateArray(arr1, N);
        int *arr2 = new int[N];
        cout << getMySortTime(arr1, arr2, N, MergeSort<int>::sort) << ',';                 // << '(' << is_sorted(arr2, arr2 + N) << ')';
        cout << getMySortTime(arr1, arr2, N, QuickSort<int>::sort) << ',';                 // << '(' << is_sorted(arr2, arr2 + N) << ')';
        cout << getMySortTime(arr1, arr2, N, QuickSort<int>::randomizedSort) << ',';       // << '(' << is_sorted(arr2, arr2 + N) << ')';
        cout << getMySortTime(arr1, arr2, N, InsertionSort<int>::sort) << ',';             //<< '(' << is_sorted(arr2, arr2 + N) << ')';
        cout << getMySortTime(arr1, arr2, N, QuickSort<int>::sort, true) << ',';           // << '(' << is_sorted(arr2, arr2 + N) << ')';
        cout << getMySortTime(arr1, arr2, N, QuickSort<int>::randomizedSort, true) << ','; // << '(' << is_sorted(arr2, arr2 + N) << ')';

        cout << getSTLSortTime(arr1, arr2, N) << endl;
        delete[] arr1, arr2;
    }
    return 0;
}