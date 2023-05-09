#include<bits/stdc++.h>
using namespace std;

class Graph{
    int numV;
    list<int>* adj;
    bool* visited;
    list<int>* L;

    public:
    Graph(int vertices){
        numV=vertices;
        adj=new list<int>[numV];
        visited =new bool[numV];
        L=new list<int>[(int)ceil(log2(numV))+1];
    }
    void addEdge(int s,int d){
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    void bfs(int s){
        int i=0;
        for(int i=0;i<numV;i++){
            visited[i]=false;
        }
        
       L[0].push_back(s);
        visited[s]=true;
        
        while (!L[i].empty())
        {
            for(auto j:L[i]){
                for(auto k:adj[j]){
                    if(!visited[k]){
                        visited[k]=true;
                        L[i+1].push_back(k);
                    }
                }
            }i++;
        }
        for(int i=0;i<log2(numV) && !L[i].empty();i++){
            cout<<"LEVEL "<<i<<"  ";
            for(auto j:L[i]){
                cout<<j+1<<" ";
            }cout<<endl;
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

  g.bfs(8);
  return 0;
}