/**
 * @file    AdjacencyMatrix.cpp
 * @brief   Adjacency matrix representation of a graph.
 *
 * The adjacency matrix representation of a graph is a square matrix,
 * where each element represents the presence or absence of an edge between
 * two vertices.
 *
 * @author  Troy
 * @date    2026-02-17
 */
#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int vertices)
{
    numVertices = vertices;
    matrix.resize(vertices, vector<int>(vertices, 0));
}

void AdjacencyMatrix::addEdge(int u, int v, int weight)
{
    matrix[u][v] = weight;
    matrix[v][u] = weight; // undirected
}

void AdjacencyMatrix::removeEdge(int u, int v)
{
    matrix[u][v] = 0;
    matrix[v][u] = 0;
}

bool AdjacencyMatrix::hasEdge(int u, int v) const
{
    return matrix[u][v] != 0;
}

void AdjacencyMatrix::print() const
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
