/**
 * @file    AdjacencyMatrix.h
 * @brief   Adjacency matrix representation of a graph.
 *
 * The adjacency matrix representation of a graph is a square matrix,
 * where each element represents the presence or absence of an edge between
 * two vertices.
 *
 * @author  Troy
 * @date    2026-02-17
 */
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <vector>

using namespace std;

/**
 * @brief   Adjacency matrix representation of a graph.
 *
 * The adjacency matrix representation of a graph is a square matrix,
 * where each element represents the presence or absence of an edge between
 * two vertices.
 */
class AdjacencyMatrix
{
private:
    int numVertices;            // number of vertices
    vector<vector<int>> matrix; // adjacency matrix

public:
    /**
     * @brief   Constructor for the AdjacencyMatrix class.
     *
     * @param[in]   vertices    The number of vertices in the graph.
     */
    AdjacencyMatrix(int vertices);

    /**
     * @brief   Add an edge to the graph.
     *
     * @param[in]   u   The source vertex.
     * @param[in]   v   The destination vertex.
     * @param[in]   weight  The weight of the edge (default is 1).
     */
    void addEdge(int u, int v, int weight = 1);

    /**
     * @brief   Remove an edge from the graph.
     *
     * @param[in]   u   The source vertex.
     * @param[in]   v   The destination vertex.
     */
    void removeEdge(int u, int v);

    /**
     * @brief   Check if there is an edge between two vertices.
     *
     * @param[in]   u   The source vertex.
     * @param[in]   v   The destination vertex.
     *
     * @return  True if there is an edge between u and v, false otherwise.
     */
    bool hasEdge(int u, int v) const;

    /**
     * @brief   Print the adjacency matrix.
     */
    void print() const;
};

#endif
