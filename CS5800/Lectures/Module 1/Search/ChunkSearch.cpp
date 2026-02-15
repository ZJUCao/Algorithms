/**
 * @file    ChunkSearch.cpp
 * @brief   Chunk search for an element x in an array A[0..n-1].
 *
 * Chunk search is a search algorithm that divides the array into chunks of size c.
 * It checks the last element of each chunk, if the element is smaller or equal to x,
 * it searches the entire chunk. The chunk size is sqrt(n).
 * It works for sorted arrays.
 *
 * Time complexity: O(sqrt(n))
 *
 * @author  Troy
 * @date    2026-02-14
 */
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if ((i > 0) && (arr[i] < arr[i - 1]))
        {
            cout << "Array is not sorted" << endl;
            return -1;
        }
    }

    // Chunk size
    int c = sqrt(n);

    int x;
    cin >> x;

    // Chunk search
    for (int i = c; i < n; i += c)
    {
        if (x > arr[i])
        {
            continue;
        }

        for (int j = i - c + 1; j < i; j++)
        {
            if (arr[j] == x)
            {
                cout << "A[" << j << "] = " << x << endl;
                return 0;
            }
        }

        break;
    }

    cout << "Not found" << endl;

    return 0;
}
