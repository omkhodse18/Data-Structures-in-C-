#include<bits/stdc++.h>
using namespace std;

int helper(int *ans,int n){
    if(n==0 ||n==1||n==2||n==3){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int minimum = INT_MAX;
    for(int i=1; i*i<= n;i++){
        minimum = min(minimum,1+helper(ans,n-i*i));
    }

    return minimum;
}

int minsquare(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }

    return helper(ans,n);
}

int main(){

}