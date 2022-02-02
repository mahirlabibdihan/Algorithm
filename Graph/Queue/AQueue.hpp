#ifndef __A_QUEUE__
#define __A_QUEUE__
#include "Queue.hpp"

// Array-based queue implementation
template <typename E>
class AQueue : public Queue<E>
{
private:
    static const int defaultSize = 10;
    int maxSize;  // Maximum size of queue
    int front;    // Index of front element
    int rear;     // Index of rear element
    E *listArray; // Array holding queue elements
    void expand()
    {
        // Reallocating memory to store more elements
        E *tmp = new E[2 * maxSize - 1];

        for (int i = 1; i < maxSize; i++)
        {
            tmp[i] = listArray[(front + i - 1) % maxSize];
        }
        front = 1;
        rear = maxSize - 1;
        maxSize = 2 * maxSize - 1;
        delete[] listArray;
        listArray = tmp;
    }

public:
    AQueue(int size = defaultSize)
    { // Constructor
        // Make list array one position larger for empty slot
        maxSize = size + 1;
        rear = 0;
        front = 1;
        listArray = new E[maxSize];
    }
    ~AQueue() { delete[] listArray; } // Destructor
    void clear()
    {
        // Reinitialize
        delete[] listArray;
        rear = 0;
        front = 1;
        listArray = new E[maxSize];
    }
    void enqueue(const E &it)
    { // Put "it" in queue
        if (length() == maxSize - 1)
        {
            expand();
        }
        rear = (rear + 1) % maxSize; // Circular increment
        listArray[rear] = it;
    }
    E dequeue()
    { // Take element out
        Assert(length() != 0, "Queue is empty");
        E it = listArray[front];
        front = (front + 1) % maxSize; // Circular increment
        return it;
    }
    int length() const // Return length
    {
        return ((rear + maxSize) - front + 1) % maxSize;
    }
    const E &frontValue() const
    { // Get front value
        Assert(length() != 0, "Queue is empty");
        return listArray[front];
    }
    const E &rearValue() const
    { // Get front value
        Assert(length() != 0, "Queue is empty");
        return listArray[rear];
    }
};
#endif