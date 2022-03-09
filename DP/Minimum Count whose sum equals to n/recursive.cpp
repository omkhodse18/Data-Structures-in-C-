#include<bits/stdc++.h>
using namespace std;

int minsquare(int n){
    if(n==0 || n==1 || n==2 || n==3){
        return n;
    }

    int ans = INT_MAX;

    for(int i=1;i*i <= n;i++){
        ans = min(ans,1+minsquare(n-i*i));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<minsquare(n);
}