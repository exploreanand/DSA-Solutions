#include <iostream>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>> adjLs, vector<int> &isVis){
        isVis[node] = 1;
        for(auto it : adjLs[node]){
            if(!isVis[it]){
                dfs(it, adjLs, isVis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);;
        vector<int> isVis(n, 0);

        // Made the Adjacency list from the given matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!isVis[i]){
                cnt++;
                dfs(i, adjLs, isVis);
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}