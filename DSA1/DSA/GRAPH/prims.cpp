#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph{
    int V;
    vector<pair<int,int>>*arr;
    queue<int> q;
    bool* vis;
    Graph(int V){
        this->V=V;
        arr=new vector<pair<int,int>>[V];
        vis=new bool[V];
    }
    void addEdge(int s,int d,int w){
        arr[s].push_back(make_pair(d,w));
        arr[d].push_back(make_pair(s,w));
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<"|"<<i<<"|";
            for(auto x:arr[i]) cout<<"->"<<x.first<<"("<<x.second<<")";
            cout<<endl;
        }
    }
    void prims(){
        

    }
};

int main(){
    Graph g1(5);
    int g[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            if(g[i][j])g1.addEdge(i,j,g[i][j]);
        }
    }
    g1.print();
    

}