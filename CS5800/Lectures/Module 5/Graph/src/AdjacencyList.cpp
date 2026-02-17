/**
 * @file    AdjacencyList.cpp
 * @brief   Adjacency list representation of a graph.
 *
 * The adjacency list representation of a graph is a collection of linked lists,
 * where each linked list represents the neighbors of a vertex.
 *
 * @author  Troy
 * @date    2026-02-17
 */
#include <iostream>
#include <algorithm>
#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList(int vertices)
{
    numVertices = vertices;
    adj.resize(vertices);
}

void AdjacencyList::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

void AdjacencyList::removeEdge(int u, int v)
{
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

void AdjacencyList::print() const
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << ": ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
