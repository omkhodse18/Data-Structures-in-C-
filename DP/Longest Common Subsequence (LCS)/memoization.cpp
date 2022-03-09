#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int lcs(string s,string t,int **ans){
    int i = s.size();
    int j = t.size();

    if(s.size()==0 || t.size()==0){
        return 0;
    }

    if(ans[i][j] != -1){
        return ans[i][j];
    }

    int output;
    if(s[0] == t[0]){
        output = 1 + lcs(s.substr(1),t.substr(1),ans);
    }
    else{
        int a = lcs(s.substr(1),t,ans);
        int b = lcs(s,t.substr(1),ans);
        int c = lcs(s.substr(1),t.substr(1),ans);
        output = max(a,max(b,c));
    }

    ans[i][j] = output;

    return ans[i][j];
}

int lcs(string s,string t){
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j] = -1;
        }
    }

    return lcs(s,t,ans);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2);
}