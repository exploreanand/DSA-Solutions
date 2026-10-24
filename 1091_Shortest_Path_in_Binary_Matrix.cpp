#include <iostream>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int m = grid.size();
        if(grid[m - 1][m - 1] != 0) return -1;
        if(m == 1) return 1;
        vector<vector<bool>> isVis(m, vector<bool>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        isVis[0][0] = 1;

        vector<int> nr = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> nc = {1, 1, 0, -1, -1, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int lvl = q.front().second;
            q.pop();

            for(int k = 0; k < 8; k++){
                int n_row = r + nr[k];
                int n_col = c + nc[k];
                
                if(n_row >= 0 && n_col >= 0 && n_row < m && n_col < m && 
                    isVis[n_row][n_col] == 0 && grid[n_row][n_col] == 0){
                    isVis[n_row][n_col] = 1;
                    if(n_row == m - 1 && n_col == m - 1) return lvl + 1;
                    q.push({{n_row, n_col}, lvl + 1});
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}