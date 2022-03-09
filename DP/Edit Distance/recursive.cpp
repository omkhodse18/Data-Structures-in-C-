#include<bits/stdc++.h>
using namespace std;

int editDistance(string s,string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }

    if(s[0] == t[0]){
        return editDistance(s.substr(1),t.substr(1));
    }else{
        int a = editDistance(s.substr(1),t) + 1;
        int b = editDistance(s,t.substr(1)) + 1;
        int c = editDistance(s.substr(1),t.substr(1)) + 1;
        return min(a,min(b,c));
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    // string s = "abcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdfabcdf";
	// string t = "afdiafdafdafdafd";
    cout<<editDistance(s,t);
}