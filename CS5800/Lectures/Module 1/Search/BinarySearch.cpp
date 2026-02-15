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
        if ((i > 0) && (arr[i] < arr[i - 1]))
        {
            cout << "Array is not sorted" << endl;
            return -1;
        }
    }

    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else if (arr[m] > x)
        {
            r = m - 1;
        }
        else
        {
            cout << "A[" << m << "] = " << x << endl;
            return 0;
        }
    }

    cout << "Not found" << endl;

    return 0;
}