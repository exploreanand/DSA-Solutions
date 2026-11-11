#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int a){
        size.resize(a, 1);
        parent.resize(a);
        for(int i = 0; i < a; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unite_by_size(int u, int v){
        int root_u = findParent(u);
        int root_v = findParent(v);
        if(root_u == root_v) return;
        if(size[root_u] < size[root_v]){
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else{
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        // Get the grid size
        int maxRow = 0;
        int maxCol = 0;
        for(auto& it : stones){
            int i = it[0];
            int j = it[1];
            maxRow = max(i, maxRow);
            maxCol = max(j, maxCol);
        }

        int totalSize = maxRow + maxCol + 2;
        DSU obj(totalSize);

        // unordered_set<int> set;
        for(auto& it : stones){
            int i = it[0];
            int j = it[1];

            int i_node = i;
            int j_node = maxRow + j + 1;

            obj.unite_by_size(i_node, j_node);
        }
        
        // for(auto& it : stones){
        //     set.insert(obj.findParent(it[0]));
        // }

        // int no_comp = set.size();

        // int max_removes = stones.size() - no_comp;

        int no_comp = 0;
        for(int i = 0; i < totalSize; i++){
            if(obj.parent[i] == i && obj.size[i]>1){
                no_comp++;
            }
        }

        int max_removes = stones.size() - no_comp;

        return max_removes;
    }
};

int main()
{

    return 0;
}