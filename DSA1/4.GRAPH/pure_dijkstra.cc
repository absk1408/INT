#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int max_i = 999;
void dijkstra(int src, vector<vector<pair<int,int>>> &adj, int V) {
    vector<int> dist(V, max_i);
    vector<bool> visited(V, false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;   // (dist, node)

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {

        auto top = pq.top();
        pq.pop();

        int u = top.second;

        // If already finalized, skip
        if(visited[u]) continue;

        visited[u] = true;   // FINALIZE

        for(auto &edge : adj[u]) {

            int v = edge.first;
            int w = edge.second;

            // Relax only if v is not finalized
            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 0; i < V; i++) {
        cout << "Distance from " << src
             << " to " << i
             << " = " << dist[i] << endl;
    }
}

int main() {

    int V = 3;
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,1});
    adj[0].push_back({2,4});
    adj[1].push_back({2,3});   // must be NON-negative

    dijkstra(0, adj, V);
}
