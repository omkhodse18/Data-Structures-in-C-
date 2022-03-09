#include<bits/stdc++.h>
using namespace std;

int minCostPath(int **input,int m,int n){
    int **ans = new int*[m];
    for(int i=0;i<m;i++){
        ans[i] = new int[n];
    }

    // Last cell
    ans[m-1][n-1] = input[m-1][n-1];

    // fillint last row from right to left <--
    for(int col = n-2; col>=0;col--){
        ans[m-1][col] = input[m-1][col] + ans[m-1][col+1];
    }

    // filling last column from bottom to top
    for(int row = m-2; row>=0; row--){
        ans[row][n-1] = input[row][n-1] + ans[row+1][n-1];
    }

    for(int row = m-2; row>=0;row--){
        for(int col = n-2; col>=0;col--){
            ans[row][col] = min(ans[row][col+1], min(ans[row+1][col+1],ans[row+1][col])) + input[row][col];
        }
    }

    return ans[0][0];
}

int main(){
    int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}

    cout<<minCostPath(input,m,n);
}