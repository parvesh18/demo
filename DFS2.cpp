#include<bits/stdc++.h>
using namespace std;
class Graph{
    int numV;
    list<int>* adj;
    bool* visited;

    public:
    Graph(int vertices){
        numV=vertices;
        adj=new list<int>[numV];
        visited =new bool[numV];
    }
    void addEdge(int s,int d){
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    void dfs(int s){
        for(int i=0;i<numV;i++){
            visited[i]=false;
        }
       stack<int> stk;
       stk.push(s);
       while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        if(!visited[u]){
            cout<<u<<" ";
            visited[u]=true;
        }
        for(auto i:adj[u]){
            if(!visited[i]){
                stk.push(i);
            }
        }
       }

    }
};
int main(){
    Graph g(13);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(6, 7);
  g.addEdge(1, 3);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 6);
  g.addEdge(2, 7);
  g.addEdge(2, 4);
  g.addEdge(3, 4);

  g.addEdge(4, 5);
  g.addEdge(8, 9);
  g.addEdge(10, 11);
  g.addEdge(11, 12);

    g.dfs(0);
  return 0;
}