#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous)
{
    int n = G.numVertices;

    vector<int> distance(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, 0);

    priority_queue<Edge> pq;
    pq.push(Edge(source, source));
    distance[source] = 0;

    while(!pq.empty())
    {
        Edge current = pq.top();
        pq.pop();

        int u = current.dst;

        if (visited[u]) continue;

        visited[u] = 1;

        for (auto neighbor : G[u])
        {
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Edge(u, v, distance[v]))
            }

        }
    }

    return distance;
}
