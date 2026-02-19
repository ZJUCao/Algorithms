/**
 * @file BinaryHeap.h
 * @brief Binary Heap class
 *
 * A binary heap is a complete binary tree that satisfies the heap property.
 * The heap property states that for every node i other than the root,
 * the value of node i is greater than or equal to the value of its parent.
 *
 * @author Troy
 * @date 2026-02-19
 */
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>

using namespace std;

template <typename T, typename Compare = less<T>>
class BinaryHeap
{
private:
    vector<T> heap;  // The vector to store the heap elements
    int currentSize; // The current size of the heap

    void HeapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (Compare()(heap[index], heap[parent]))
            {
                break;
            }

            T temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        }
    }

    void HeapifyDown(int index)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if ((left < currentSize) && Compare()(heap[left], heap[smallest]))
            {
                smallest = left;
            }

            if ((right < currentSize) && Compare()(heap[right], heap[smallest]))
            {
                smallest = right;
            }

            if (smallest == index)
            {
                break;
            }

            T temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        }
    }

public:
    /**
     * @brief Construct a new Binary Heap object
     */
    BinaryHeap()
    {
        currentSize = 0;
    }

    /**
     * @brief Construct a new Binary Heap object from a vector of values
     *
     * @param values
     */
    BinaryHeap(const vector<T> &values)
    {
        heap = values;
        currentSize = values.size();

        for (int i = (currentSize / 2 - 1); i >= 0; i--)
        {
            HeapifyDown(i);
        }
    }

    /**
     * @brief Destroy the Binary Heap object
     */
    ~BinaryHeap()
    {
        heap.clear();
    }

    /**
     * @brief Check if the heap is empty
     *
     * @return true  If the heap is empty
     * @return false  If the heap is not empty
     */
    bool IsEmpty() const
    {
        return (currentSize == 0);
    }

    /**
     * @brief Get the current size of the heap
     *
     * @return int  The current size of the heap
     */
    int GetSize() const
    {
        return currentSize;
    }

    /**
     * @brief Insert a value into the heap
     *
     * @param[in]   value  The value to insert
     * @return  int  0 if successful, -1 if unsuccessful
     */
    int Insert(T value)
    {
        heap.push_back(value);
        HeapifyUp(currentSize);
        currentSize++;

        return 0;
    }

    /**
     * @brief Find the minimum value in the heap
     *
     * @return T  The minimum value in the heap
     */
    T FindMin() const
    {
        if (IsEmpty())
        {
            return -1;
        }

        return heap[0];
    }

    /**
     * @brief Delete the minimum value in the heap
     *
     * @return int  0 if successful, -1 if unsuccessful
     */
    int DeleteMin()
    {
        if (IsEmpty())
        {
            return -1;
        }

        currentSize--;
        heap[0] = heap[currentSize];
        heap.pop_back();

        if (currentSize > 0)
        {
            HeapifyDown(0);
        }

        return 0;
    }
};

#endif