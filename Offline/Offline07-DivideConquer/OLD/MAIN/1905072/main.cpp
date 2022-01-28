#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>
using namespace std;
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

// Array = [0,RAND_MAX=32767]
void generateArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
void copyArray(int *mainArray, int *tempArray, int n)
{
    for (int j = 0; j < n; j++)
    {
        tempArray[j] = mainArray[j];
    }
}

template <typename E>
double getSTLSortTime(E *mainArray, E *tempArray, int n, bool isSorted = false, int totalTest = 20)
{
    double avg = 0;
    for (int i = 0; i < totalTest; i++)
    {
        if (!isSorted)
        {
            copyArray(mainArray, tempArray, n);
        }
        auto startTime = chrono::high_resolution_clock::now();
        sort(tempArray, tempArray + n);
        auto endTime = chrono::high_resolution_clock::now();
        avg += chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / 1000000.0;
    }
    return avg / totalTest;
}

template <typename E, typename Comp>
double getMySortTime(E *mainArray, E *tempArray, int n, void (*mySort)(E *, int, int, Comp), bool isSorted = false, int totalTest = 20)
{
    double avg = 0;
    for (int i = 0; i < totalTest; i++)
    {
        if (!isSorted)
        {
            copyArray(mainArray, tempArray, n);
        }
        auto startTime = std::chrono::high_resolution_clock::now();
        mySort(tempArray, 0, n - 1, Comp());
        auto endTime = std::chrono::high_resolution_clock::now();
        avg += chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / 1000000.0;
    }
    return avg / totalTest;
}
int main()
{
    freopen("output.csv", "w", stdout);
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
        cout << getMySortTime(mainArray, tempArray, N, MergeSort<int>::sort) << ',';                 // << '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << getMySortTime(mainArray, tempArray, N, QuickSort<int>::sort) << ',';                 // << '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << getMySortTime(mainArray, tempArray, N, QuickSort<int>::randomizedSort) << ',';       // << '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << getMySortTime(mainArray, tempArray, N, InsertionSort<int>::sort) << ',';             //<< '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << getMySortTime(mainArray, tempArray, N, QuickSort<int>::sort, true) << ',';           // << '(' << is_sorted(tempArray, tempArray + N) << ')';
        cout << getMySortTime(mainArray, tempArray, N, QuickSort<int>::randomizedSort, true) << ','; // << '(' << is_sorted(tempArray, tempArray + N) << ')';

        cout << getSTLSortTime(mainArray, tempArray, N) << endl;
        delete[] mainArray, tempArray;
    }
    return 0;
}