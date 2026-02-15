/**
 * @file    LinearSearch.cpp
 * @brief   Linear search for an element x in an array A[0..n-1].
 *
 * Linear search is a simple search algorithm that checks each element in the array
 * sequentially until the desired element is found or the end of the array is reached.
 * It works for both sorted and unsorted arrays.
 *
 * Time complexity: O(n)
 *
 * @author  Troy
 * @date    2026-02-14
 */
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "A[" << i << "] = " << x << endl;
            return 0;
        }
    }

    cout << "Not found" << endl;

    return 0;
}
