#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int,int> pd;

struct Graph{
    int V;
    vector<pair<int,int>>*arr;
    queue<int> q;
    bool* vis;
    int* wt;
    priority_queue<pd,vector<pd>,greater<pd>> pq;

    Graph(int V){
        this->V=V;
        arr=new vector<pair<int,int>>[V];
        vis=new bool[V];
        wt=new int[V];
        fill_n(wt,V,INT32_MAX);
        fill_n(vis,V,false);
    }
    void addEdge(int s,int d,int w){
        arr[s].push_back(make_pair(d,w));
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<"|"<<i<<"|";
            for(auto x:arr[i]) cout<<"("<<x.first<<"|"<<x.second<<")";
            cout<<endl;
        }
    }
    void dijkstra(int s=0){
        wt[s]=0;
        pq.push(make_pair(0,s));
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for (auto x : arr[u]) {
                int v = x.first;  // Neighbor vertex
                int weight = x.second;  // Edge weight

                // If there is a shorter path to v through u
                if (wt[u] + weight < wt[v]) {
                    wt[v] = wt[u] + weight;
                    pq.push(make_pair(wt[v], v));  // Push updated distance to priority queue
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<wt[i]<<" ";
        }
    }
};

int main() {
    Graph g1(9);
    int a[9][9] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    // Add edges to the graph
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] > 0) {
                g1.addEdge(i, j, a[i][j]);
            }
        }
    }

    g1.print();  // Optional: To print the adjacency list

    cout << "\nShortest distances from vertex 0:\n";
    g1.dijkstra();  // Run Dijkstra's algorithm from vertex 0

    return 0;
}