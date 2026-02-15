/**
 * @file    MergeSort.cpp
 * @brief   Merge sort for an array A[0..n-1].
 *
 * Merge Sort is a divide-and-conquer algorithm that sorts an array by dividing it into two halves,
 * sorting each half recursively, and then merging the sorted halves.
 *
 * Time Complexity: O(n*log n)
 *
 * @author  Troy
 * @date    2026-02-15
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief   Merge two sorted subarrays into one sorted array.
 *
 * @param[in]   arr     The array to be sorted.
 * @param[in]   left    The left index of the subarray.
 * @param[in]   mid     The middle index of the subarray.
 * @param[in]   right   The right index of the subarray.
 */
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

/**
 * @brief   Recursively sort an array using the merge sort algorithm.
 *
 * @param[in]   arr     The array to be sorted.
 * @param[in]   left    The left index of the subarray.
 * @param[in]   right   The right index of the subarray.
 */
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
