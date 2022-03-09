#include<bits/stdc++.h>
using namespace std;

int helper(int *ans,int h){
    if(h<=1){
        return 1;
    }

    int mod = (int) (pow(10,9) + 7);
    if(ans[h] != -1){
        return ans[h];
    }

    int x = helper(ans,h-1);
    int y = helper(ans,h-2);

    int temp1 = (int) (((long) (x) * x) % mod);
    int temp2 = (int) ((2 * (long)(x) * y) % mod);

    int output = (temp1 + temp2) % mod;
    ans[h] = output;
    return ans[h];
}

int balancedBTs(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }

    return helper(ans,n);
}

int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h);
}