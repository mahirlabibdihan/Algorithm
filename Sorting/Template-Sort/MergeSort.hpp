#ifndef __MERGE_SORT__
#define __MERGE_SORT__
namespace Merge
{
    template <class Comp>
    Comp comp;
    template <typename E, typename Comp>
    void merge(E begin, E mid, E end)
    {
        E mergedArray = new typename remove_pointer<E>::type[end - begin];
        // Merging begin and end sub-Array in a temporary Array in sorted order.
        for (E i = begin, j = mid, k = mergedArray; i != mid || j != end; k++)
        {
            if (i == mid) // Left sublist exhausted
                *k = *j++;
            else if (j == end) // Right sublist exhausted
                *k = *i++;
            else if (comp<Comp>(*i, *j))
                *k = *i++;
            else
                *k = *j++;
        }
        // Copying the temporary Array back to Original Array
        for (E i = begin, k = mergedArray; i != end;)
        {
            *i++ = *k++;
        }
    }
    // Recursive way
    template <typename E, typename Comp>
    void divide(E begin, E end)
    {
        if (begin + 1 >= end)
        {
            return; // List of one/zero element
        }
        E mid = begin + (end - begin) / 2;
        divide<E, Comp>(begin, mid);
        divide<E, Comp>(mid, end);
        merge<E, Comp>(begin, mid, end);
    }
    // Iterative way: Bottom up approach
    template <typename E, typename Comp>
    void msort(E begin, E end, Comp comp)
    {
        Merge::comp<Comp> = comp;
        for (int curr_size = 1; curr_size <= end - begin; curr_size = 2 * curr_size)
        {
            // for (E i = begin; i < end; i++)
            // {
            //     cout << *i << " ";
            // }
            // cout << endl;
            for (E left = begin; left < end - 1; left += 2 * curr_size)
            {
                E mid = left + min(curr_size, end - left + 1);
                E right = left + min(2 * curr_size, end - left + 1);
                merge<E, Comp>(left, mid, right);
            }
        }
    }
    /*
    Merge Sort
    begin: Start point of sorting
    end: End point of sorting
    Comp: Comparator which will decide the order of sorting
    */
    template <typename E, typename Comp>
    void sort(E begin, E end, Comp comp)
    {
        Merge::comp<Comp> = comp;
        divide<E, Comp>(begin, end);
    }
}
#endif