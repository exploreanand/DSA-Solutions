#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    using pi = pair<int, pair<int, int>>;
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> least_head(n, vector(n, INT_MAX));
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        vector<int> n_row = {0, 1, 0, -1};
        vector<int> n_col = {1, 0, -1, 0};

        // Initialise pq and least_head
        least_head[0][0] = grid[0][0];
        pq.push({least_head[0][0], {0, 0}});

        while(!pq.empty()){
            int head = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n -1 && col == n -1) return head;
            if (head > least_head[row][col]) continue;

            for(int i = 0; i < 4; i++){
                int n_r = row + n_row[i];
                int n_c = col + n_col[i];
                
                if(n_r >= 0 && n_c >= 0 && n_r < n && n_c < n){
                    int new_head = max(head , grid[n_r][n_c]);

                    // I forget to implement this below check
                    if(new_head < least_head[n_r][n_c]){
                        least_head[n_r][n_c] = new_head;
                        pq.push({least_head[n_r][n_c], {n_r, n_c}});
                    }
                }
            }
        }
        return least_head[n-1][n-1];
    }
};

int main()
{

    return 0;
}