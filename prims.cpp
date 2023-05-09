#include<bits/stdc++.h>
using namespace std;
//list of pairs
// index denotes u pair first denotes wight and second denotes v
class Graph{
    int V;
    list<pair<int,int>>* adj;
    int *parent,*key;
    bool* mst;
    public:
    Graph(int v){
        V=v;
        adj=new list<pair<int,int>>[V];
        parent=new int[V];
        key=new int[V];
        mst=new bool[V];
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void prim(){
        //creating min heap 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int source=0;
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            mst[i]=false;
            parent[i]=-1;
        }
        pq.push(make_pair(0,source));
        key[source]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();

            if(mst[u]){
                continue;
            }
            mst[u]=true;
            for(auto i: adj[u]){
                int v=i.first;
                int w=i.second;
                if(!mst[v] && key[v]>w){
                    key[v]=w;
                    pq.push(make_pair(key[v],v));
                    parent[v]=u;
                }
            }
        }
        for(int i=1;i<V;i++){
            cout<<parent[i]<<"  "<<i<<endl;
        }
 }
};
int main(){
int V = 4;
    Graph g(V);
 
    
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 7);
    g.addEdge(2, 3, 5);
 
    g.prim();
 }