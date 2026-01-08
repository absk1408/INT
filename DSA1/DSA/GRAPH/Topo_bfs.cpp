#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph{
    int V;
    vector<int>*arr;
    queue<int> q;
    queue<int>q1;
    bool* vis;
    int* indeg;
    Graph(int V){
        this->V=V;
        arr=new vector<int>[V];
        vis=new bool[V];
        indeg=new int[V]{0};
    }
    void addEdge(int s,int d){
        arr[s].push_back(d);
        indeg[d]++;

    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<"|"<<i<<"|";
            for(auto x:arr[i]) cout<<"->"<<x;
            cout<<endl;
        }
    }
    void bfs1(int s=0){
        q.push(s);
        vis[s]=true;
        while(!q.empty()){
            for(auto x:arr[q.front()]){
                if(vis[x]==false){
                    q.push(x);
                    vis[x]=true;
                }
            }
            cout<<q.front();
            q.pop();
        }
    }
    void bfs(int s=0){
        for(s;s<V;s++){
            if(vis[s]==false) bfs1(s);
        }
    }
    void topo(int i=0){
        for(i;i<V;i++){
            if(!indeg[i]) q1.push(i);
        }
        while(!q1.empty()){
            int s=q1.front();
            for(auto x:arr[s]){
                indeg[x]--;
                if(indeg[x]==0) q1.push(x);
            }
            cout<<s;
            q1.pop();
        }
    }
};

int main(){
    Graph g1(5);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(2,3);
    g1.addEdge(1,4);
    g1.addEdge(1,3);
    g1.print();
    g1.bfs();cout<<endl;
    g1.topo();
    

}