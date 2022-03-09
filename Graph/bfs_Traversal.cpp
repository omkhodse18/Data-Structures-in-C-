#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges,int n,int sv,bool* visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";

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
}

void bfs_traversal(int** edges,int n){
    bool* visited = new bool[n];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++){
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

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<endl;
    bfs_traversal(edges,n);

}

// 8
// 8
// 0 1
// 0 2
// 0 3
// 1 4
// 1 5
// 2 6
// 2 7
// 3 7