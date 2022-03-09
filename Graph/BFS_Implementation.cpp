#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edge,int n,int sv,bool *visited){
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;

    while(pendingVertex.size() != 0){
        int currentIndex = pendingVertex.front();
        pendingVertex.pop();
        cout<<currentIndex<<endl;

        for(int i=0;i<n;i++){
            if(i==currentIndex){
                continue;
            }

            if(edge[currentIndex][i]==1){
                if(visited[i]){
                    continue;
                }

                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edge,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    printBFS(edge,n,0,visited);
    delete[] visited;
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


    BFS(edge,n);

    for(int i=0;i<n;i++){
        delete[ ] edge[i];
    }

    delete[] edge;

}