#include <iostream>
using namespace std;

class Solution {
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dis_matrix(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        dis_matrix[0][0] = 0;

        vector<int> n_row = {0, 1, 0, -1};
        vector<int> n_col = {1, 0, -1, 0};

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            if(row == m - 1 && col == n - 1) return effort;

            if(effort > dis_matrix[row][col]){
                continue;
            }

            for(int i = 0; i < 4; i++){
                int r = row + n_row[i];
                int c = col + n_col[i];
                if(r >= 0 && r < m && c >= 0 && c < n){
                    int dif = abs(heights[row][col] - heights[r][c]);
                    int new_effort = max(effort, dif);

                    if(new_effort < dis_matrix[r][c]){
                        dis_matrix[r][c] = new_effort;
                        pq.push({new_effort, {r, c}});
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{

    return 0;
}