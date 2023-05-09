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

    void bfs(int s){
        queue<int> que;
        for(int i=0;i<numV;i++){
            visited[i]=false;
        }
        que.push(s);
        visited[s]=true;
        while (!que.empty())
        {
            int currV=que.front();
            cout<<"Visited "<<currV+1<<" ";
            que.pop();
            for(auto i:adj[currV]){
                if(!visited[i]){
                    visited[i]=true;
                    que.push(i);
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

  g.bfs(0);
  return 0;
}