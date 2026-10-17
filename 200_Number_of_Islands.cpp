#include <iostream>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &isVal, pair<int, int> node, int n, int m){
        
        queue<pair<int, int>> q;
        q.push(node);
        isVal[node.first][node.second] = 1;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            if(temp.second + 1 < m && grid[temp.first][temp.second + 1] == '1' && isVal[temp.first][temp.second + 1] == 0){
                q.push({temp.first, temp.second + 1});
                isVal[temp.first][temp.second + 1] = 1;
            }
            if(temp.first + 1 < n && grid[temp.first + 1][temp.second] == '1' && isVal[temp.first + 1][temp.second] == 0){
                q.push({temp.first + 1, temp.second});
                isVal[temp.first + 1][temp.second] = 1;
            }
            if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == '1' && isVal[temp.first][temp.second - 1] == 0){
                q.push({temp.first, temp.second - 1});
                isVal[temp.first][temp.second - 1] = 1;
            }
            if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == '1' && isVal[temp.first - 1][temp.second] == 0){
                q.push({temp.first - 1, temp.second});
                isVal[temp.first - 1][temp.second] = 1;
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> isVal(n, vector<int>(m, 0));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && isVal[i][j] != 1){
                    pair<int, int> p = {i, j};
                    cnt++;
                    dfs(grid, isVal, p, n, m);
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}