#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	vector<int> inDeg;
	vector<bool> visited;
	public:
	Graph(int V){
		this->V=V;
		adj=new list<int>[V];
		inDeg.resize(V,0);
		visited.resize(V,false);
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	void indeg(list<int> &q){
		for(int i=0;i<V;i++){
			for(auto x:adj[i]){
				inDeg[x]++;
			}
		}
		for(int i=0;i<V;i++){
			if(!inDeg[i]){
				q.push_back(i);
			}
		}
	}
	void kahn(){
		list<int> q;
		indeg(q);
		while(!q.empty()){
			int x=q.front();
			visited[x]=true;
			cout<<x<<" ";
			q.pop_front();
			for(auto i:adj[x]){
				inDeg[i]--;
				if(!inDeg[i]&&!visited[i]){
					q.push_back(i);
				}
			}
		}
	}
};
int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout<<"Topological sorts: "<<endl; 
    g.kahn();
    return 0;
}