#include<bits/stdc++.h>
using namespace std;

class solution{
private:
bool isSafe(int row,int column,int n,vector<vector<int>> visited,vector<vector<int>> &originalArr){
    if((row>=0 && row < n) && (column>=0 && column<n) && visited[row][column]==0 && originalArr[row][column]==1){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>> &originalArr,int n, vector<string> &ans,int row,int column,
            vector<vector<int>> visited,string path){

    if(row == n-1 && column == n-1){
        ans.push_back(path);
        return;
    }

    visited[row][column] = 1;

    //down
    int newRow = row+1;
    int newColumn = column;
    if(isSafe(newRow,newColumn,n,visited,originalArr)){
        path.push_back('D');
        solve(originalArr,n,ans,newRow,newColumn,visited,path);
        path.pop_back();
    }

    //left
    newRow = row;
    newColumn = column-1;
    if(isSafe(newRow,newColumn,n,visited,originalArr)){
        path.push_back('L');
        solve(originalArr,n,ans,newRow,newColumn,visited,path);
        path.pop_back();
    }
    //right
    newRow = row;
    newColumn = column+1;
    if(isSafe(newRow,newColumn,n,visited,originalArr)){
        path.push_back('R');
        solve(originalArr,n,ans,newRow,newColumn,visited,path);
        path.pop_back();
    }
    //Up
    newRow = row-1;
    newColumn = column;
    if(isSafe(newRow,newColumn,n,visited,originalArr)){
        path.push_back('U');
        solve(originalArr,n,ans,newRow,newColumn,visited,path);
        path.pop_back();
    }

    visited[row][column] = 0;
}

public:
vector<string> findPath(vector<vector<int>> &originalArr,int n){

    vector<string> ans;

    if(originalArr[0][0]==0){
        return ans;
    }

    int row = 0;
    int column = 0;

    vector<vector<int>> visitedArr = originalArr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visitedArr[i][j] = 0;
        }
    }

    string path = " ";
    solve(originalArr,n,ans,row,column,visitedArr,path);
    sort(ans.begin(),ans.end());
    return ans;
}
};

