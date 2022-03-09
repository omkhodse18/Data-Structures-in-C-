#include <iostream>
#include <vector>
using namespace std;
#define MAXN 51
int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};
bool isCyclePresent(vector<vector<char>> &board, int n, int m, int sourceX, int sourceY, int x, int y, int count, bool **isVisited){
    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX == sourceX && nextY == sourceY && count >= 4) return true;
    }

    for(int i = 0; i < 4; i++){
        int nextX = x+moveX[i];
        int nextY = y+moveY[i];

        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m){
            if(board[nextX][nextY] == board[x][y] && !isVisited[nextX][nextY]){
                isVisited[nextX][nextY] = true;
                if(isCyclePresent(board, n, m, sourceX, sourceY, nextX, nextY, count+1, isVisited)){
                    return true;
                }
                isVisited[nextX][nextY] = false;
            }
        }
    }

    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool **isVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        isVisited[i] = new bool[m];
        for(int j = 0; j < m; j++) isVisited[i][j] = false;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!isVisited[i][j]){
                isVisited[i][j] = true;
                if(isCyclePresent(board, n, m, i, j, i, j, 1, isVisited)) return 1;
                isVisited[i][j] = false;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}