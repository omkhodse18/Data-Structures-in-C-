#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int h) {
    int mod = (int) (pow(10, 9)) + 7;
    long dp[h+1];
    dp[0] = dp[1] = 1; 

    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h];
}

int main(){
    int n;
    cin>>n;
    cout<<balancedBTs(n);
}