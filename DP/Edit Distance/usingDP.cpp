#include<bits/stdc++.h>
using namespace std;

int editDistance(string s,string t){
    int m = s.size();
    int n = t.size();

    int **ans = new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i] = new int[n+1];
    }

    //fill first row
    for(int j=0;j<=n;j++){
        ans[0][j] = j;
    } 

    //fill first col   
    for(int i=0;i<=m;i++){
        ans[i][0] = i;
    }    

    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i] == t[n-j]){
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                int a = ans[i-1][j] + 1;
                int b = ans[i][j-1] + 1;
                int c = ans[i-1][j-1] + 1;
                ans[i][j] = min(a,min(b,c));
            }
        }
    }

    return ans[m][n];
}

int main(){
    string s,t;
    cin>>s>>t;
    // string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	// string t = "afdiafdafdafdafd";
    cout<<editDistance(s,t);
}