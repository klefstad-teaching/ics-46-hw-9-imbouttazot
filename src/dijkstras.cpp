#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
int numVert = G.size();
vector<int> distances(numVert, INF);
vector<bool> visited(numVert, false);
distances[source] = 0;
previous[source] = undefined;
priority_queue<pair<int,int>> minHeap;
minHeap.push({source, 0});

while (!minHeap.empty()){
    int index = minHeap.top().second;
    minHeap.pop();
    if (visited[index])
        continue;
    visited[index] = true;
    for (Edge e : G[index]){
        int ed = e.dst;
        int weight = e.weight;
        if (visited[ed] && distances[index] + weight < distances[ed]){
            distances[ed] = distances[index] + weight;
            previous[ed] = index;
            minHeap.push(ed, distances[ed]);
        }
    }
}
return distances;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){

vector<int> path;
    if (distances[destination] == INF) {
        return {};
    }

    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;

}
void print_path(const vector<int>& v, int total){

 cout << "Shortest path (cost " << total << "): ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << endl;

}