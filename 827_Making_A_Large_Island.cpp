#include <iostream>
#include <vector>
#include <algorithm>
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
        if(root_u == root_v) return;
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

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(j + 1 < n && grid[i][j + 1] == 1){
                        obj.uniteSize(i * n + j, i * n + (j + 1));
                    }
                    if(i + 1 < n && grid[i + 1][j] == 1){
                        obj.uniteSize(i * n + j, (i + 1) * n + j);
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

        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;

                int root[4];
                int rootCount = 0;

                for(int k = 0; k < 4; k++){
                    int n_r = i + row[k];
                    int n_c = j + col[k];

                    if(n_r >= 0 && n_c >= 0 && n_r < n && n_c < n && grid[n_r][n_c] == 1){
                        int nod = n_r * n + n_c;
                        int rt = obj.findParents(nod);

                        bool dublicate = false;
                        for(int idx = 0; idx < rootCount; idx++){
                            if(root[idx] == rt){
                                dublicate = true;
                                break;
                            }
                        }

                        if(!dublicate){
                            root[rootCount] = rt;
                            rootCount++;
                        }
                    }
                }

                int sum = 1;
                for(int it = 0; it < rootCount; it++){
                    sum += obj.size[root[it]];
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}