#include<bits/stdc++.h>
using namespace std;

int helper(int *ans,int n){
    if(n==0){
        return 1;
    }

    if(n==1 || n==2){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int ans1 = helper(ans,n-1);
    int ans2 = helper(ans,n-2);
    int ans3 = helper(ans,n-3);

    return ans1+ans2+ans3;
}

int staircase(int n){
    int *ans = new int[n+1];

    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }

    return helper(ans,n);
}

int main(){
    int n;
    cin>>n;

    cout<<staircase(n);
}