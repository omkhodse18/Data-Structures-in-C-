#include<bits/stdc++.h>
using namespace std;

int fib_num(int n){
    if(n == 1 || n==0){
        return n;
    }

    return fib_num(n-1) + fib_num(n-2);
}

int main(){
    int n;
    cin>>n;

    // int i=0;
    // while(i < n){
    //     cout<<fib_num(i)<<" ";
    //     i++;
    // }

    cout<<endl<<fib_num(n)<<" ";
}