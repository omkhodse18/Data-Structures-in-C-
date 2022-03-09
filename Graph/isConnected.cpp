#include<bits/stdc++.h>
using namespace std;

void DFS(int** edges,int n,int sv,bool* visited){
    visited[sv] = true;
    
    for(int i=0;i<n;i++){
        if(i == sv){
            continue;
        }

        if(edges[sv][i] == 1 && !visited[i]){
            DFS(edges,n,i,visited);
        }
    }
}

bool isConnected(int** edges,int n,bool* visited){
    DFS(edges,n,0,visited);

    for(int i=0;i<n;i++){
        if(visited[i] == false){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    int e;
    cin>>n>>e;

    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }

    bool* visited = new bool[n];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<n;i++){
        if(visited[i] == true);
    }

    isConnected(edge,n,visited) ? cout<<"true" : cout<<"false";

}