/**
 * @file IntervalScheduling.cpp
 * @brief Interval scheduling problem
 *
 * @author Troy
 * @date 2026-02-19
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Interval scheduling problem
 *
 * @param[in]   intervals   The vector of intervals
 * @return      int         The maximum number of non-overlapping intervals
 */
int intervalScheduling(vector<pair<int, int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
    {
        return 0;
    }

    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int count = 1;
    int endTime = intervals[0].second;
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].first >= endTime)
        {
            count++;
            endTime = intervals[i].second;
        }
    }

    return count;
}

int main(void)
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the start time and end time of interval " << i + 1 << ": ";
        cin >> intervals[i].first >> intervals[i].second;
    }

    int maxCount = intervalScheduling(intervals);
    cout << "Maximum number of non-overlapping intervals: " << maxCount << endl;

    return 0;
}