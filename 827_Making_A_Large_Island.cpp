#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DSU{
    vector<int> parents;
public:
    vector<int> size;
    DSU(int a){
        size.resize(a, 1);
        parents.resize(a);
        for(int i = 0; i < a; i++){
            parents[i] = i;
        }
    }

    int findParents(int u){
        if(parents[u] == u) return u;

        return parents[u] = findParents(parents[u]);
    }

    void uniteSize(int u, int v){
        int root_u = findParents(u);
        int root_v = findParents(v);
        if(size[root_u] < size[root_v]){
            parents[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else{
            parents[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DSU obj(n*n);

        vector<vector<bool>> isVis(n, vector<bool>(n, false));

        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 || isVis[i][j] == true) continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                isVis[i][j] = true;

                while(!q.empty()){
                    auto [r, c] = q.front();
                    q.pop();

                    int node = r * n + c;
            
                    for(int k = 0; k < 4; k++){
                        int n_r = r + row[k];
                        int n_c = c + col[k];
                        if(n_r >= 0 && n_c >= 0 && n_r < n && n_c < n && isVis[n_r][n_c] == false && grid[n_r][n_c] == 1){
                            isVis[n_r][n_c] = true;
                            int nod = n_r * n + n_c;
                            obj.uniteSize(node, nod);
                            q.push({n_r, n_c});
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n*n; i++){
            if(grid[i/n][i%n] == 1){
                ans = max(ans, obj.size[obj.findParents(i)]);
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;

                unordered_set<int> sett;
                for(int k = 0; k < 4; k++){
                    int n_r = i + row[k];
                    int n_c = j + col[k];

                    if(n_r >= 0 && n_c >= 0 && n_r < n && n_c < n && grid[n_r][n_c] == 1){
                        int nod = n_r * n + n_c;
                        sett.insert(obj.findParents(nod));
                    }
                    int sum = 1;
                    for(auto it : sett){
                        sum += obj.size[it];
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}