#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int** edges,int n,int sv,bool* visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    vector<int> ans;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        ans.push_back(currentVertex);
        pendingVertices.pop();

        for(int i=0;i<n;i++){
            if(i == sv){
                continue;
            }

            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }

    }
    return ans;
}

void allConnected(int** edges,int n,bool* visited){
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> ans = BFS(edges,n,i,visited);
            sort(ans.begin(),ans.end());
            for(int j=0;j<ans.size();j++){
                cout<<ans.at(j)<<" ";
            }
            cout<<endl;
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

    bool* visited = new bool[n];
    memset(visited,false,sizeof(visited));
    allConnected(edges,n,visited);
}