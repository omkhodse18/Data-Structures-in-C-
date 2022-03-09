#include<bits/stdc++.h>
using namespace std;

int helper(int *arr,int n){
    if(n == 1 || n==0){
        return n;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int a = helper(arr,n-1);
    int b = helper(arr,n-2);

    arr[n] = a + b;

    return arr[n];
}

int fib(int n){
    int *arr = new int[n + 1];
    for(int i=0;i<n+1;i++){
        arr[i] = -1;
    }

    return helper(arr,n);
}

int main(){
    int n;
    cin>>n;

    int i=0;
    while(i < n){
        cout<<fib(i)<<" ";
        i++;
    }

    cout<<endl<<fib(n);
}