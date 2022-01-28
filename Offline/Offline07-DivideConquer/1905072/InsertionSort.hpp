#ifndef __INSERTION_SORT__
#define __INSERTION_SORT__
namespace Insertion
{
    /*
    Insertion Sort
    begin: Start point of sorting
    end: End point of sorting
    Comp: Comparator which will decide the order of sorting
    */
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
#endif