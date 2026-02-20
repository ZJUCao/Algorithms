/**
 * @file main.cpp
 * @brief Main function
 *
 * @author Troy
 * @date 2026-02-19
 */
#include <iostream>
#include "UnionFind.h"

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    UnionFind uf = UnionFind(n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        uf.Union(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        cout << uf.Find(i) << endl;
    }

    return 0;
}