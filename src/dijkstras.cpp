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

    while (!pq.empty())
    {
        Edge current = pq.top();
        pq.pop();

        int u = current.dst;

        if (visited[u])
            continue;

        visited[u] = 1;

        for (auto neighbor : G[u])
        {
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push(Edge(u, v, distance[v]));
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int> &, const vector<int> &previous, int destination)
{
    vector<int> path;
    for (size_t i = destination; i != -1; previous[i])
    {
        path.push_back(i);
    }
    return path;
}

void print_path(const vector<int> &v, int total)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << "\nTotal cost: " << total << endl;
}
