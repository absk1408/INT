#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph{
    int V;
    vector<int>*arr;
    queue<int> q;
    bool* vis;
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
    void bfs(){
        q.push(0);
        vis[0]=true;
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
};

int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,3);
    g1.addEdge(0,2);
    g1.addEdge(1,4);
    //g1.addEdge(3,4);
    g1.addEdge(2,4);
    g1.print();
    g1.bfs();
    

}