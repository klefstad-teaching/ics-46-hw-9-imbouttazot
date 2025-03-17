#include "dijkstras.h"
#include <vector>
#include <queue>
#include <limits>

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
            minHeap.push({ed, distances[ed]});
        }
    }
}
return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){

vector<int> path;
    if (distances[destination] == INF) {
        return {};
    }

    stack<int> tempStack;
    for (int v = destination; v != -1; v = previous[v]) {
        tempStack.push(v);
    }

    while (!tempStack.empty()) {
        path.push_back(tempStack.top());
        tempStack.pop();
    }
    
    return path;

}
void print_path(const vector<int>& v, int total){

 std::cout << "Shortest path (cost " << total << "): ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1) cout << " -> ";
    }
    std::cout << std::endl;

}