#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct Graph{
    int V;
    vector<int>*arr;
    queue<int> q;
    bool* vis;
    int count;
    stack<int> st;
    Graph(int V){
        this->V=V;
        arr=new vector<int>[V];
        vis=new bool[V];
        count=0;
    }
    void addEdge(int s,int d){
        arr[s].push_back(d);
        //arr[d].push_back(s);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<"|"<<i<<"|";
            for(auto x:arr[i]) cout<<"->"<<x;
            cout<<endl;
        }
    }
    void dfs(int i=0){
        for(i;i<V;i++){ 
            if(vis[i]==false){
                topo(i);          
            } 
        }
        print_topo();
    }
    void topo(int s){
        vis[s]=true;
        for(auto x:arr[s]){
            if(vis[x]==false) topo(x);
        }
        st.push(s);
    }
    void print_topo(){
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
    }
};
int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,3);
    g1.addEdge(3,4);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.print();
    g1.dfs();
    

}