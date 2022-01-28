#ifndef __QUICK_SORT__
#define __QUICK_SORT__
namespace Quick
{
    enum Mode
    {
        LAST_PIVOT,
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
        else
        {
            return left + (rand() % (right - left + 1));
        }
    }
    template <typename E, typename Comp>
    E partition(E left, E right)
    {
        E pivotIdx = findPivot(left, right);
        swap(*pivotIdx, *right); // Put pivot at right
        E i = left - 1;
        for (E j = left; j < right; j++)
        {
            if (comp<Comp>(*j, *right))
            {
                swap(*++i, *j);
            }
        }
        swap(*++i, *right); // Put pivot in place
        return i;           // Return first position in right partition
    }

    template <class E, class Comp>
    void divide(E left, E right)
    {
        if (right <= left)
        {
            return; // Don’t sort 0 or 1 element
        }
        // k will be the first position in the right subarray, where the pivot will be after partition
        E k = Quick::partition<E, Comp>(left, right);
        divide<E, Comp>(left, k - 1);
        divide<E, Comp>(k + 1, right);
    }
    /*
    Quick Sort
    begin: Start point of sorting
    end: End point of sorting
    Comp: Comparator which will decide the order of sorting
    */
    template <class E, class Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        Quick::comp<Comp> = comp;
        Quick::pivotMode = LAST_PIVOT;
        divide<E, Comp>(begin, end - 1);
    }
    /*
    Randomized quick Sort
    begin: Start point of sorting
    end: End point of sorting
    Comp: Comparator which will decide the order of sorting
    */
    template <class E, class Comp>
    void rsort(const E begin, const E end, Comp comp)
    {
        Quick::comp<Comp> = comp;
        Quick::pivotMode = RANDOM_PIVOT;
        divide<E, Comp>(begin, end - 1);
    }
}
#endif