#include <iostream>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node, int curr_color){
        color[node] = 1 - curr_color;
        curr_color = color[node];
        for(int it : graph[node]){
            if(color[it] != -1){
                if(color[it] == color[node]) return false;
            }
            else{
                if(dfs(graph, color, it, curr_color) == false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(graph, color, i, 0) == false) return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}