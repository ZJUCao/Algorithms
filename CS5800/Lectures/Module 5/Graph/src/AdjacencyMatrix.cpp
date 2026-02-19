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
#include <queue>
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

void AdjacencyMatrix::BFS(int start) const
{
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if (matrix[v][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void AdjacencyMatrix::dfsUtil(int v, vector<bool> &visited) const
{
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < numVertices; i++)
    {
        if (matrix[v][i] != 0 && !visited[i])
        {
            dfsUtil(i, visited);
        }
    }
}

void AdjacencyMatrix::DFS(int start) const
{
    vector<bool> visited(numVertices, false);

    cout << "DFS: ";
    dfsUtil(start, visited);
    cout << endl;
}