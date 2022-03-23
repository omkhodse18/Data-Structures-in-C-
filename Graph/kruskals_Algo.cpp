#include<bits/stdc++.h>
using namespace std;

class Edges{
    public:
    int source;
    int destination;
    int weight;
};

bool compare(Edges e1,Edges e2){
    return e1.weight < e2.weight;
}

int findPath(int v,int* parent){
    if(parent[v] == v){
        return v;
    }

    return findPath(parent[v],parent);
}

void kruskals(Edges *input,int n, int e){
    sort(input,input+e,compare);

    Edges* output = new Edges[n-1];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }   

    int count = 0;
    int i = 0;

    while(count != n-1){
        Edges currentEdge = input[i];
        int currentSource = findPath(currentEdge.source,parent);
        int currentDest = findPath(currentEdge.destination,parent);

        if(currentSource != currentDest){
            output[count] = currentEdge;
            count++;
            parent[currentSource] = currentDest;
        }
        i++;
    }

    for(int i=0;i<n-1;i++){
        if(output[i].source < output[i].destination){
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    Edges *input = new Edges[e];

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }    

    kruskals(input,n,e);
    return 0;
}

// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8