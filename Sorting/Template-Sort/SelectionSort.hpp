#ifndef __SELECTION_SORT__
#define __SELECTION_SORT__
namespace Selection
{
    template <class E, class Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        E min;

        // Worst Swaps: (n - 1) + (n - 2) + ..... + 1 = n(n + 1)/2 - n
        // Best Swaps: (n - 1) + (n - 2) + ..... + 1 = n(n + 1)/2 - n

        // One by one move boundary of unsorted subarray
        for (E i = begin; i < end - 1; i++)
        {
            // Find the minimum element in unsorted array
            min = i;
            for (E j = i + 1; j < end; j++)
            {
                if (comp(*j, *min)) // Ascending
                {
                    min = j;
                }
            }
            // Swap the found minimum element with the first element
            swap(*i, *min);
        }
    }
}
#endif