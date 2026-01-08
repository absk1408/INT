#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graph{
    int V;
    vector<pair<int,int>>*arr;
    queue<int> q;
    bool* vis;
    int* wt;
    Graph(int V){
        this->V=V;
        arr=new vector<pair<int,int>>[V];
        vis=new bool[V];
        wt=new int[V];
        fill_n(wt,V,INT32_MAX);
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
    void short_DAG1(int s){
        vis[s]=true;
        for(auto x:arr[s]){
            if(!vis[x.first]){
                int mx=wt[s]+x.second;
                if(wt[x.first]>mx){
                    wt[x.first]=mx;
                }
                short_DAG1(x.first);
            }
        }

    }
    void short_DAG(int s=0){
        wt[s]=0;
        short_DAG1(s);
        for(int i=0;i<V;i++){
            cout<<wt[i]<<" ";
        }
    }

};

int main(){
    Graph g1(9);
    /*g1.addEdge(0,1,2);
    g1.addEdge(1,2,3);
    g1.addEdge(2,3,6);
    g1.addEdge(0,4,1);
    g1.addEdge(4,2,2);
    g1.addEdge(4,5,4);
    g1.addEdge(5,3,1);*/
    int a[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]>0){
                g1.addEdge(i,j,a[i][j]);
            }
        }
    }
    g1.print();
    g1.short_DAG(0);
}