#include<bits/stdc++.h>
using namespace std;

int minsteps(int n){
    if(n <= 1){
        return 0;
    }

    int a = minsteps(n-1);

    int b = INT_MAX,c = INT_MAX;
    if(n%2 == 0){
        b = minsteps(n/2);
    }

    if(n%3 == 0){
        b = minsteps(n/3);
    }

    int ans = min(a,min(c,b)) + 1;

    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<minsteps(n);
}