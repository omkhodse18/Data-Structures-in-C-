#include<bits/stdc++.h>
using namespace std;

int editDistance(string s,string t,int **ans){
    int m = s.size();
    int n = t.size();

    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }

    if(ans[m][n] != -1){
        return ans[m][n];
    }

    int output;
    if(s[0] == t[0]){
        output = editDistance(s.substr(1),t.substr(1),ans);
    }else{
        int a = editDistance(s.substr(1), t, ans) + 1;
        int b = editDistance(s, t.substr(1), ans) + 1;
        int c = editDistance(s.substr(1), t.substr(1), ans) + 1;
        output =  min(a,min(b,c));
    }

    ans[m][n] = output;
    return output;
}

int editDistance(string s,string t){
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j] = -1;
        }
    }

    return editDistance(s,t,ans);
}

int main(){
    // string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	// string t = "afdiafdafdafdafd";

    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t);
}