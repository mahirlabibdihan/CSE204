#include "heap.h"
int main()
{
    vector<int> v = {1, 4, 3, 2, 5, 6};
    Heap h(v);
    heapsort(v);
    for (int i : v)
    {
        cout << i << " ";
    }
}