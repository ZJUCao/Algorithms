/**
 * @file main.cpp
 * @brief Main function to test the Binary Heap class
 *
 * @author Troy
 * @date 2026-02-19
 */
#include <iostream>
#include <vector>
#include "BinaryHeap.h"

using namespace std;

int main(void)
{
    vector<int> values;
    int value;

    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        values.push_back(value);
    }

    BinaryHeap<int> heap = BinaryHeap<int>(values);

    cout << "Size of heap: " << heap.GetSize() << endl;
    while (!heap.IsEmpty())
    {
        cout << heap.FindMin() << endl;
        heap.DeleteMin();
    }

    return 0;
}