#include<bits/stdc++.h>
using namespace std;

int staircase(int n){
    if(n==0){
        return 1;
    }

    if(n==1 || n==2){
        return n;
    }

    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<staircase(n);
}