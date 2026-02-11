#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;
struct Edge {
    int u, v, w;
};
void bellmanFord(int V, vector<Edge>& edges, int src) {

    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <=1; i++) {
        for(auto &e : edges) {
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    // Check negative cycle
    for(auto &e : edges) {
        if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }
    // Print result
    for(int i = 0; i < V; i++) {
        cout << "Distance from " << src
             << " to " << i
             << " = " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<Edge> edges = {
        {0,1,10},
        {1,2,5},
        {2,3,5},
        {3,1,-9},   // positive cycle overall
        {3,4,1},
        {4,5,1}
    };
    bellmanFord(V, edges, 0);
    return 0;
}
