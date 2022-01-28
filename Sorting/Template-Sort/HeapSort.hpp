#ifndef __HEAP_SORT__
#define __HEAP_SORT__
namespace Heap
{
    template <typename E, typename Comp>
    void heapifyArray(const E arr, const int &n, int root, Comp comp)
    {
        int largest = root;       //initialize root as largest element
        int left = 2 * root + 1;  //left child
        int right = 2 * root + 2; //right child
        // If left child is larger than root
        if (left < n)
        {
            if (comp(arr[largest], arr[left]))
            {
                largest = left;
            }
        }
        // If right child is larger than largest so far
        if (right < n)
        {
            if (comp(arr[largest], arr[right]))
            {
                largest = right;
            }
        }

        if (largest != root) //largest elemnt jodi root na hoy..
        {
            swap(arr[largest], arr[root]);       //swap korey dibo
            heapifyArray(arr, n, largest, comp); //recursively heapify
        }
    }

    // To heapify the whole tree we need to heapify all the non-leaf elements. From bottom to root.
    template <typename E, typename Comp>
    void heapify(const E begin, const E end, Comp comp)
    {
        // Iterative
        // In array representation,	0th to (n/2)-1 th elements are non-leaf elements
        for (E i = begin + ((end - begin) / 2) - 1; i >= begin; i--)
        {
            heapifyArray(begin, end - begin, i - begin, comp);
        }
    }

    template <typename E, typename Comp>
    void sort(const E begin, const E end, Comp comp)
    {
        heapify(begin, end, comp);
        // We will delete the root of the heap, until the heap is empty.
        // So we will delete the maximum element of the heap everytime
        for (E i = end - 1; i > begin; i--)
        {
            swap(*begin, *i);                        // move current root to end
            heapifyArray(begin, i - begin, 0, comp); // call max heapify on the reduced heap
                                                     // max heap - Ascending order
                                                     // min heap - Descending order
        }
    }
} // namespace HeapSort

#endif