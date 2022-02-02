/* A Program to sort the array using Introsort.
The most popular C++ STL Algorithm- sort()
uses Introsort. */

#include <iostream>
#include <cmath>
using namespace std;

#include "HeapSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"

#ifndef __INTRO_SORT__
#define __INTRO_SORT__
// Worst case: Already sorted array
namespace Intro
{
    enum Mode
    {
        LAST_PIVOT,
        FIRST_PIVOT,
        MID_PIVOT,
        RANDOM_PIVOT,
        MEDIAN_PIVOT
    } pivotMode;
    /*
    MEDIAN_PIVOT: Worst case = O(nlogn)
    RANDOM_PIVOT: Worst case = O(n^2)
    */
    template <class Comp>
    Comp comp;
    template <class E>
    E MedianOfThree(E a, E b, E c)
    {
        if (*a < *b && *b < *c)
            return (b);

        if (*a < *c && *c <= *b)
            return (c);

        if (*b <= *a && *a < *c)
            return (a);

        if (*b < *c && *c <= *a)
            return (c);

        if (*c <= *a && *a < *b)
            return (a);

        if (*c <= *b && *b <= *a)
            return (b);
    }
    template <class E>
    E findPivot(E left, E right)
    {
        if (pivotMode == LAST_PIVOT)
        {
            return right;
        }
        else if (pivotMode == FIRST_PIVOT)
        {
            return left;
        }
        else if (pivotMode == MID_PIVOT)
        {
            return left + (right - left) / 2;
        }
        else if (pivotMode = RANDOM_PIVOT)
        {
            return left + (rand() % (right - left + 1));
        }
        else
        {
            return MedianOfThree(left, left + (right - left) / 2, right);
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
    void divide(const E begin, const E end, int depthLimit)
    {
        if (end <= begin)
        {
            return; // Don’t sort 0 or 1 element
        }
        int size = end - begin;
        if (size < 16)
        {
            Insertion::sort(begin, end + 1, comp<Comp>);
            return;
        }
        // If the depth is zero use heapsort
        if (depthLimit == 0)
        {
            Heap::sort(begin, end + 1, comp<Comp>);
            return;
        }
        // k will be the first position in the right subarray, where the pivot will be after partition
        E k = Quick::partition<E, Comp>(begin, end);
        divide<E, Comp>(begin, k - 1, depthLimit - 1);
        divide<E, Comp>(k + 1, end, depthLimit - 1);
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
        Intro::comp<Comp> = comp;
        Intro::pivotMode = MEDIAN_PIVOT;
        int depthLimit = 2 * log(end - begin);
        divide<E, Comp>(begin, end - 1, depthLimit);
    }
}
#endif