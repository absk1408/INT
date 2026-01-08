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
    int *dis;
    priority_queue<pd,vector<pd>,greater<pd>> pq;

    Graph(int V){
        this->V=V;
        arr=new vector<pair<int,int>>[V];
        vis=new bool[V];
        wt=new int[V];
        fill_n(wt,V,INT32_MAX);
        fill_n(vis,V,false);
        dis=new int[V];
        fill_n(dis,V,INT32_MAX);
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
    void bellman(int s=0){
        dis[s]=0;
        for(int i=0;i<V-1;i++){
            for(int u=0;u<V;u++){
                for(auto x:arr[u]){
                    if(dis[u]!=INT32_MAX){
                        int w=dis[u]+x.second;
                        if(dis[x.first]>w) dis[x.first]=w;
                    }
                }
            }
        }
        for(int i=0;i<V;i++) cout<<dis[i]<<" ";

    }
};

int main() {
    Graph g1(4);
    g1.addEdge(0,1,1);
    g1.addEdge(0,2,4);
    g1.addEdge(1,2,-3);
    g1.addEdge(1,3,2);
    g1.addEdge(2,3,3);
    g1.print();
    g1.bellman();
    

    return 0;
}