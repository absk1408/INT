#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph{
    int V;
    vector<int>*arr;
    queue<int> q;
    bool* vis;
    int* p;
    Graph(int V){
        this->V=V;
        arr=new vector<int>[V];
        vis=new bool[V];
    }
    void addEdge(int s,int d){
        arr[s].push_back(d);
        arr[d].push_back(s);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<"|"<<i<<"|";
            for(auto x:arr[i]) cout<<"->"<<x;
            cout<<endl;
        }
    }
    bool dfs(int s,int p){
        vis[s]=true;
        for(auto x:arr[s]){
            if(x==p) continue;
            else if(!vis[x]&&dfs(x,s)) return true;
        }
        return false;
    }
    bool iscycle(int s=0){
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1)) return true;
            }
        }
        return false;
    }
};

int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,4);
    g1.addEdge(3,2);
    
    //g1.addEdge(4,3);
    g1.print();cout<<endl;
}