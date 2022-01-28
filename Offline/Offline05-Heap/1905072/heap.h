#ifndef __HEAP__
#define __HEAP__
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
/*
If we start indexing from 1 instead of 0.
Left Child = 2*i = i<<2
Right Child = 2*i+1 = i<<2|1
Parent = i/2 = i>>2
n/2<i<n -> leaf
*/
// heapArray class
class Heap
{
protected:
    int *heapArray; // Pointer to the heapArray array
    static const int defaultSize = 10;
    int maxSize; // Maximum size of the heapArray
    int n;       // Number of elements now in the heapArray
    // Helper function to put element in its correct place
    // O(logh)
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int largest = pos;
            int lc = leftChild(pos);
            int rc = rightChild(pos);
            if ((lc < n) && (heapArray[lc] > heapArray[largest]))
            {
                largest = lc; // Set lc to greater child’s value
            }
            if ((rc < n) && (heapArray[rc] > heapArray[largest]))
            {
                largest = rc; // Set rc to greater child’s value
            }
            if (largest == pos)
            {
                return;
            }
            swap(heapArray[pos], heapArray[largest]); // Swap with child
            pos = largest;                            // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 0 && (heapArray[pos] > heapArray[parent(pos)]))
        {
            swap(heapArray[pos], heapArray[parent(pos)]); // Swap with parent
            pos = parent(pos);                            // Move up
        }
    }
    bool isLeaf(int pos) const // True if pos is a leaf
    {
        return (pos >= n / 2) && (pos < n);
    }
    int leftChild(int pos) const
    {
        return 2 * pos + 1;
    } // Return leftchild position
    int rightChild(int pos) const
    {
        return 2 * pos + 2;
    }                         // Return rightchild position
    int parent(int pos) const // Return parent position
    {
        return (pos - 1) / 2;
    }
    void expand()
    {
        int *temp = new int[2 * maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            temp[i] = heapArray[i];
        }
        maxSize *= 2;
        delete[] heapArray;
        heapArray = temp;
    }
    void operator=(const Heap &) {} // Protect assignment
    Heap(const Heap &) {}           // Protect copy constructor
public:
    Heap(int max = defaultSize)
    {
        maxSize = max;
        heapArray = new int[maxSize];
        n = 0;
    }
    Heap(vector<int> &v) // Constructor
    {
        maxSize = n = v.size();
        heapArray = new int[maxSize];
        for (int i = 0; i < n; i++)
        {
            heapArray[i] = v[i];
        }
        buildHeap();
    }
    ~Heap()
    {
        delete[] heapArray;
    }
    int size() const // Return current heapArray size
    {
        return n;
    }
    // O(n)->Tighter Bound
    void buildHeap() // Heapify contents of heapArray
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            shiftDown(i);
        }
    }
    // Insert "it" into the heapArray
    void insert(const int &it)
    {
        if (n == maxSize)
        {
            expand();
        }
        n++;
        heapArray[n - 1] = it; // Start at end of heapArray
        // Now shift up until curr’s parent > curr
        if (n > 1) // If the heap is empty or consists of one node we are done
        {
            shiftUp(n - 1);
        }
    }
    // Remove first value: O(logn)
    void deleteKey()
    {
        if (n == 0)
        {
            cout << "Heap is empty";
            return;
        }
        swap(heapArray[0], heapArray[--n]); // Swap first with last value
        if (n > 1)                          // If the heap is empty or consists of one node we are done
        {
            shiftDown(0); // shiftdown new root val
        }
    }
    int getMax()
    {
        Assert(n > 0, "Heap is empty");
        return heapArray[0]; // Return deleted value
    }
};
#endif
#ifndef __HEAP_SORT__
#define __HEAP_SORT__
void heapsort(vector<int> &v)
{
    // O(n)
    Heap *H = new Heap(v); // Build the heapArray
    int n = v.size();      // Heapsort
    // O(nlogn)
    for (int i = 0; i < n; i++) // Now sort
    {
        // O(logn)
        v[i] = H->getMax(); // Place maxval at end
        H->deleteKey();
    }
    delete H;
}
#endif