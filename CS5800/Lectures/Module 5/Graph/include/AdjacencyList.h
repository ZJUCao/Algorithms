/**
 * @file    AdjacencyList.h
 * @brief   Adjacency list representation of a graph.
 *
 * The adjacency list representation of a graph is a collection of linked lists,
 * where each linked list represents the neighbors of a vertex.
 *
 * @author  Troy
 * @date    2026-02-17
 */
#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <vector>

using namespace std;

/**
 * @brief   Adjacency list representation of a graph.
 *
 * The adjacency list representation of a graph is a collection of linked lists,
 * where each linked list represents the neighbors of a vertex.
 */
class AdjacencyList
{
private:
    int numVertices;         // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    /**
     * @brief   Constructor for the AdjacencyList class.
     *
     * @param[in]   vertices    The number of vertices in the graph.
     */
    AdjacencyList(int vertices);

    /**
     * @brief   Add an edge to the graph.
     *
     * @param[in]   u   The source vertex.
     * @param[in]   v   The destination vertex.
     */
    void addEdge(int u, int v);

    /**
     * @brief   Remove an edge from the graph.
     *
     * @param[in]   u   The source vertex.
     * @param[in]   v   The destination vertex.
     */
    void removeEdge(int u, int v);

    /**
     * @brief   Print the adjacency list.
     */
    void print() const;
};

#endif
