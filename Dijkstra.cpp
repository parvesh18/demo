#include<bits/stdc++.h>
using namespace std;
class graph{
    int vertices,edges;
    int **adj;
    int *distance;
    bool* visited;
    int* path;
    public:
    graph(){
        cout<<"Eneter the number of vertices: ";
        cin>>vertices;
        cout<<"Enter the number of edges: ";
        cin>>edges;
        visited=new bool[vertices];
        distance=new int[vertices];
        path=new int[vertices];
        adj=new int*[vertices];
        for(int i=0;i<vertices;i++){
            adj[i]=new int[vertices];
        }
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                adj[i][j]=0;
            }
        }
        int u,v,w;
        for(int i=0;i<edges;i++){
            cin>>u>>v>>w;
            adj[u][v]=w;
            adj[v][u]=w;
        }
        // for(int i=0;i<vertices;i++){
        //     for(int j=0;j<vertices;j++){
        //         cout<<adj[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
    }
    int minDist()
    {
    // Initialize min value
        int min = INT_MAX, min_index;
 
        for (int v = 0; v < vertices; v++)
            if (visited[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;
 
        return min_index;
    }
    void dijkstra(int s){
        for(int i=0;i<vertices;i++){
            distance[i]=INT_MAX;
            visited[i]=false;   
            path[i]=0;  
        }
        distance[s]=0;
        for(int j=0;j<vertices-1;j++){
            int u=minDist();
            visited[u]=true;

            for(int v=0;v<vertices;v++){
                if(!visited[v] && adj[u][v] && distance[u]!=INT_MAX){
                    if(distance[u]+adj[u][v] <distance[v]){
                    distance[v]=distance[u]+adj[u][v];
                    path[v]=u;
                    }
                }
            }
        }
    //  
    cout<<"Source is: "<<s<<endl;
    cout<<"Destination"<<"\t"<<"Distance"<<"\t"<<"Path\n";
    for(int i=0;i<vertices;i++){
        cout<<i<<"\t\t"<<distance[i]<<"\t\t";
        printpath(s,i);cout<<endl;
    }   cout<<endl;
    
    }
    void printpath(int s,int i){
        if(path[i]==0 && s==i){
            cout<<i<<" -> ";
        }
        else{
        printpath(s,path[i]);
        cout<<i<<" -> ";
        }
        // cout<<i<<endl;
    }

};
int main(){
    graph g;
    g.dijkstra(0);
}
//                         {0,4,20,0,0,0},
//                         {4,0,11,9,7,0},
//                         {20,11,0,0,3,0},
//                         {0,9,0,0,13,2},
//                         {0,7,3,13,0,6},
//                         {0,0,0,2,6,0}};