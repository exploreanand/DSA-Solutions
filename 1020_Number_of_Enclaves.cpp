#include <iostream>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, int m, int n, pair<int, int> p, int state, int start, int &total){
        int initial = grid[p.first][p.second];
        if(initial != state){
            queue<pair<int, int>> q;
            grid[p.first][p.second] = state;
            q.push(p);
            total++;
            while(!q.empty()){
                pair<int, int> temp = q.front();
                q.pop();
                pair<int, int> l = {temp.first, temp.second - 1};
                pair<int, int> r = {temp.first, temp.second + 1};
                pair<int, int> t = {temp.first - 1, temp.second};
                pair<int, int> d = {temp.first + 1, temp.second};

                if(l.second >= start && grid[l.first][l.second] != state){
                    grid[l.first][l.second] = state;
                    q.push(l);
                    total++;
                }
                if(r.second < n && grid[r.first][r.second] != state){
                    grid[r.first][r.second] = state;
                    q.push(r);
                    total++;
                }
                if(t.first >= start && grid[t.first][t.second] != state){
                    grid[t.first][t.second] = state;
                    q.push(t);
                    total++;
                }
                if(d.first < m && grid[d.first][d.second] != state){
                    grid[d.first][d.second] = state;
                    q.push(d);
                    total++;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid){
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        for(int i = 0; i < n; i++){
            pair<int, int> p = {0, i};
            bfs(grid, m , n, p, 0, 0, total);
        }
        for(int i = 0; i < m; i++){
            pair<int, int> p = {i, n - 1};
            bfs(grid, m , n, p, 0, 0, total);
        }
        for(int i = n - 1; i >= 0; i--){
            pair<int, int> p = {m - 1, i};
            bfs(grid, m , n, p, 0, 0, total);
        }
        for(int i = m - 1; i >= 0; i--){
            pair<int, int> p = {i, 0};
            bfs(grid, m , n, p, 0, 0, total);
        }

        int cnt = 0;
        total = 0;
        m = grid.size() - 1;
        n = grid[0].size() - 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    pair<int, int> p = {i, j};
                    bfs(grid, m , n, p, 0, 1, total);
                }
            }
        }
        return total;
    }
};

int main()
{

    return 0;
}