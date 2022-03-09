#include<bits/stdc++.h>
using namespace std;

vector<int>* getPathDFS(int** edges,int n,int sv,int ev,bool* visited){
    vector<int>* solution = new vector<int>();
    if(sv == ev){
        solution->push_back(sv);
        return solution;
    }

    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(i == sv){
            continue;
        }

        if(edges[sv][i] == 1 && !visited[i]){
            vector<int>* ans = getPathDFS(edges,n,i,ev,visited);
            if(ans != nullptr){
                ans->push_back(sv);
                return ans;
            }
        }
    }

    return nullptr;
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

    int v1,v2;
    cin>>v1>>v2;
    
    vector<int>* ans = getPathDFS(edges,n,v1,v2,visited);
    if(ans != nullptr){
        for(int i=0;i<ans->size();i++){
            cout<<ans->at(i)<<" ";
        }
    }
}