#include <iostream>
#include<set>  // //label _correcting algorithm  //will fail in negative cycles also when huge graph with negative values()
#include<vector>
using namespace std;

const int INF = 1e9;

void dijkstra(int src, vector<vector<pair<int,int>>> &adj, int V) {

    vector<int> dist(V, INF);
    set<pair<int,int>> st;   // (distance, node)

    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {
        auto it = st.begin();// Get node with minimum distance
        int u = it->second;
        st.erase(it);

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v]) {
                if(dist[v] != INF) { // If v already exists in set, remove old value
                    st.erase({dist[v], v});
                }
                dist[v] = dist[u] + w;
                st.insert({dist[v], v});
            }
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

    int V = 3;
    vector<vector<pair<int,int>>> adj(V);
    // u -> v (edge/weight)
    adj[0].push_back({1,5});
    adj[0].push_back({2,1});
    adj[1].push_back({2,-3});
    dijkstra(0, adj, V); //src,vector,number of edges
    return 0;
}
