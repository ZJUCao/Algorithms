/**
 * @file UnionFind.cpp
 * @brief Union Find class implementation
 *
 * Union-Find data structure.
 *
 * @author Troy
 * @date 2026-02-19
 */
#include "UnionFind.h"

UnionFind::UnionFind(int size)
{
    this->size = size;
    parent.resize(size);
    rank.resize(size, 0);
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
    }
}

UnionFind::~UnionFind()
{
    parent.clear();
    rank.clear();
}

int UnionFind::Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX == rootY)
    {
        return -1;
    }

    if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }

    return 0;
}

int UnionFind::Find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}