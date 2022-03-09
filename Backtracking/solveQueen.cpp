#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int **board,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]==1){
            return false;
        }
    }

    //left diagonal
    int x=row;
    int y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    //right diagonal
    x=row;
    y=col;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    return true;

}

bool solve(int **board,int row,int n){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            if(solve(board,row+1,n)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int**board = new int*[n];
    for(int i=0;i<n;i++){
        board[i] = new int[n];
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }

    solve(board,0,n);
    return 0;
}