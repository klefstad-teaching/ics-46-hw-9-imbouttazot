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
    int index = minHeap.extractVertexWithMinimumWeight().first;
    if (visited[index])
        continue;
    visited[index] =  true;
    for (Edge e : g[index]){
        int ed = e.dest;
        int weight = e.second;
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

}
void print_path(const vector<int>& v, int total){

}