#include "dijkstras.h"

int main()
{
    Graph G;
    file_to_graph("src/small.txt", G);
    vector<int> p;
    int src = 0;
    int dest = 12;

    vector<int> distances = dijkstra_shortest_path(G, src, p);
    vector<int> path = extract_shortest_path(distances, p, dest);
    print_path(path, path.size());
}