#include <iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> isVis(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n - 1; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                isVis[0][i] = 1;
            }
        }
        for(int i = 0; i < m - 1; i++){
            if(board[i][n - 1] == 'O'){
                q.push({i, n - 1});
                isVis[i][n-1] = 1;
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(board[m - 1][i] == 'O'){
                q.push({m - 1, i});
                isVis[m-1][i] = 1;
            }
        }
        for(int i = m - 1; i > 0; i--){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                isVis[i][0] = 1;
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && isVis[nr][nc] == 0 && board[nr][nc] == 'O'){
                    isVis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(isVis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{

    return 0;
}