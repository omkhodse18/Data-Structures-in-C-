#include<bits/stdc++.h>
using namespace std;

vector<int>* getPathBFS(int** edges, int n, int sv,int ev,bool* visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    bool pathExist = false;
    unordered_map<int,int> mp;

    while(!pendingVertices.empty() && !pathExist){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        
        for(int i=0;i<n;i++){
            if(edges[currentVertex][i]==1 && !visited[i]){
                mp[i] = currentVertex;
                pendingVertices.push(i);
                visited[i] = true;
                if(i == ev){
                    pathExist = true;
                    break;
                }
            }
        }
    }

    if(!pathExist){
        return nullptr;
    }else{
        vector<int>* ans = new vector<int>();
        int current = ev;
        ans->push_back(ev);
        while(current != sv){
            current = mp[current];
            ans->push_back(current);
        }
        return ans;
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

    int sv,ev;
    cin>>sv>>ev;

    vector<int>* ans = getPathBFS(edges,n,sv,ev,visited);

    if(ans != nullptr){
        for(int i=0;i<ans->size();i++){
            cout<<ans->at(i)<<" ";
        }
    }
}