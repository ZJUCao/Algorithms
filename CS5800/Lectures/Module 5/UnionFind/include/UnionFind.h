/**
 * @file UnionFind.h
 * @brief Union Find class
 *
 * Union-Find data structure.
 *
 * @author Troy
 * @date 2026-02-19
 */
#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

using namespace std;

class UnionFind
{
private:
    vector<int> parent; // parent[i] is the parent of i
    vector<int> rank;   // rank[i] is the rank of i
    int size;           // size of the Union Find object

public:
    /**
     * @brief Construct a new Union Find object
     *
     * @param[in]   size  The size of the Union Find object
     */
    UnionFind(int size);

    /**
     * @brief Destroy the Union Find object
     */
    ~UnionFind();

    /**
     * @brief Union two sets
     *
     * @param[in]   x  The first set
     * @param[in]   y  The second set
     * @return  int  0 if successful, -1 if unsuccessful
     */
    int Union(int x, int y);

    /**
     * @brief Find the root of a set
     *
     * @param[in]   x  The set
     * @return  int  The root of the set
     */
    int Find(int x);
};

#endif
