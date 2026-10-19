#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return -1;

        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<vector<int>> isVis(m, vector<int>(n, 0));

        // q = {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    isVis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1){
                    isVis[i][j] = 1;
                    fresh++;
                }
            }
        }

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(int i = 0; i < 4; i++){
                int row = r + nrow[i];
                int col = c + ncol[i];
                if(row >= 0 && row < m && col >= 0 && col < n && isVis[row][col] != 2 && grid[row][col] == 1){
                    isVis[row][col] = 2;
                    q.push({{row, col}, t + 1});
                    fresh--;
                }
            }
        }

        if(fresh != 0) return -1;

        return time;
    }
};

int main()
{

    return 0;
}