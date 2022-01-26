#ifndef __COMPARATORS__
#define __COMPARATORS__
namespace Comparators
{
    template <typename E>
    bool less(const E &a, const E &b)
    {
        return a < b;
    }
    template <typename E>
    bool greater(const E &a, const E &b)
    {
        return a > b;
    }
};
#endif