#include <iostream>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool> &isVis, vector<bool> &dfsVis){
        isVis[node] = 1;
        dfsVis[node] = 1;

        for(auto it : adj[node]){
            if(isVis[it] == 0){
                if(dfs(it, adj, isVis, dfsVis) == 1) return true;
            }
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> isVis(numCourses, 0);
        vector<bool> dfsVis(numCourses, 0);

        vector<vector<int>> adj(numCourses);
        for(const auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(isVis[i] == 0){
                if(dfs(i, adj, isVis, dfsVis) == true) return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}