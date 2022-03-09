#include<bits/stdc++.h>
using namespace std;

int helper(int *arr,int n){
    if(n <= 1){
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int a = helper(arr,n-1);

    int b = INT_MAX, c = INT_MAX;
    if(n%2 == 0){
        b = helper(arr,n/2);
    }

    if(n%3 == 0){
        c = helper(arr,n/3);
    }

    int output = min(a,min(b,c)) + 1;
    arr[n] = output;

    return arr[n];

}

int minsteps(int n){
    int *arr = new int[n+1];

    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }

    return helper(arr,n);

}

int main(){
    int n;
    cin>>n;

    cout<<minsteps(n);

}