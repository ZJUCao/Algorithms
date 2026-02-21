/**
 * @file ShortestPaths.cpp
 * @brief Dijkstra's algorithm for finding the shortest path from a source vertex to a target vertex
 *
 * @author Troy
 * @date 2026-02-19
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

/**
 * @brief Dijkstra's algorithm for finding the shortest path from a source vertex to a target vertex
 *
 * @param[in]   n           The number of vertices
 * @param[in]   s           The source vertex
 * @param[in]   t           The target vertex
 * @param[in]   adj         The adjacency matrix
 * @return      int         The minimum distance from s to t
 */
int dijkstra(int n, int s, int t, vector<vector<int>> &adj)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] != 0 && dist[v] > dist[u] + adj[u][v])
            {
                dist[v] = dist[u] + adj[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    return dist[t];
}

int main(void)
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter the start vertex, end vertex, and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    int s, t;
    cout << "Enter the source vertex: ";
    cin >> s;
    cout << "Enter the target vertex: ";
    cin >> t;

    int minDist = dijkstra(n, s, t, adj);
    if (minDist == INT_MAX)
    {
        cout << "There is no path from " << s << " to " << t << endl;
    }
    else
    {
        cout << "The minimum distance from " << s << " to " << t << " is " << minDist << endl;
    }

    return 0;
}