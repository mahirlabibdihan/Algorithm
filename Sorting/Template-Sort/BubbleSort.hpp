#ifndef __BUBBLE_SORT__
#define __BUBBLE_SORT__
namespace Bubble
{
    template <class E, class Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        // Worst Swaps: (n - 1) + (n - 2) + ..... + 2 = n(n + 1)/2 - (n + 1)
        // Best Swaps: 0
        for (E i = end - 1; i > begin; i--)
        {
            for (E j = begin; j < i; j++)
            {
                if (comp(*(j + 1), *j))
                {
                    swap(*(j + 1), *j);
                }
            }
        }
    }

} // namespace Bubble
#endif