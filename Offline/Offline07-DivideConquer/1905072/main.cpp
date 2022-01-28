#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <chrono>
using namespace std;
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "InsertionSort.hpp"
/*
Template function to get elapsed time of different sorting alogorithm.
mainArray: Array that needs to be sorted.
tempArray: Temporary array which will be passed to sorting function. So that the mainArray doesn't change.
n: Size of the array
mySort: Common function pointer for different sorting functions. 
isSorted: If the array is already sorted.
totalTest: Total number of tests to find the average.
*/
template <class E, class Comp>
double getSortTime(E mainArray, E tempArray, int n, void (*mySort)(const E, const E, Comp), bool isSorted = false, int totalTest = 20)
{
    if (!isSorted)
    {
        std::copy(mainArray, mainArray + n, tempArray);
    }
    auto startTime = chrono::high_resolution_clock::now();
    mySort(tempArray, tempArray + n, Comp());
    auto endTime = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / (totalTest * 1000000.0);
}
void generateArray(int *arr, const int &n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
void solve(const int &n)
{
    double avg[7] = {};
    int *mainArray = new int[n];
    int *tempArray = new int[n];
    for (int i = 0; i < 20; i++)
    {
        generateArray(mainArray, n);
        avg[0] += getSortTime(mainArray, tempArray, n, Merge::sort<int *, less<int>>);
        avg[1] += getSortTime(mainArray, tempArray, n, Quick::sort<int *, less<int>>);
        avg[2] += getSortTime(mainArray, tempArray, n, Quick::rsort<int *, less<int>>);
        avg[3] += getSortTime(mainArray, tempArray, n, Insertion::sort<int *, less<int>>);
        avg[4] += getSortTime(mainArray, tempArray, n, Quick::sort<int *, less<int>>, true);
        avg[5] += getSortTime(mainArray, tempArray, n, Quick::rsort<int *, less<int>>, true);
        avg[6] += getSortTime(mainArray, tempArray, n, std::sort<int *, less<int>>);
    }
    cout << n;
    for (int i = 0; i < 7; i++)
    {
        cout << ',' << avg[i];
    }
    cout << '\n';
    delete[] mainArray, tempArray;
}
int main()
{
    freopen("output.csv", "w", stdout);
    srand(1905072);
    const int n[] = {5, 10, 100, 1000, 10000, 100000};
    cout << "Time,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with sorted input,Randomized Quicksort with sorted input,STL sort() function\n";
    for (int j = 0; j < sizeof(n) / sizeof(n[0]); j++)
    {
        solve(n[j]);
    }
    return 0;
}