#include<bits/stdc++.h>
using namespace std;

bool hasPath(int** edges,int n,int sv,bool* visited,int ev){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        if(currentVertex == ev){
            return true;
        }

        for(int i=0;i<n;i++){
            if(i == currentVertex){
                continue;
            }

            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    
    int** edges = new int*[n];
    for(int  i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];
    memset(visited,false,sizeof(visited));

    int v1,v2;
    cin>>v1>>v2;

    hasPath(edges,n,v1,visited,v2) ? cout<<"true" : cout<<"false";

}