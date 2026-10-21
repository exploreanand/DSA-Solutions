#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDeg(n, 0);
        vector<vector<int>> revGraph(n);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
                inDeg[i]++;
            }
        }

        queue<int> q;
        vector<bool> isSafe(n, false);
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            isSafe[temp] = true;
            for(auto it : revGraph[temp]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(isSafe[i] == true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}