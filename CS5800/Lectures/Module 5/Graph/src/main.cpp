/**
 * @file    main.cpp
 * @brief   Main program for testing the adjacency matrix and list representations of a graph.
 *
 * @author  Troy
 * @date    2026-02-17
 */
#include <iostream>
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

using namespace std;

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v):" << endl;
    AdjacencyMatrix m(numVertices);
    AdjacencyList l(numVertices);
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        m.addEdge(u, v);
        l.addEdge(u, v);
    }

    cout << "=== Adjacency Matrix ===" << endl;
    m.print();
    m.BFS(0);
    m.DFS(0);

    cout << "\n=== Adjacency List ===" << endl;
    l.print();
    l.BFS(0);
    l.DFS(0);

    return 0;
}
