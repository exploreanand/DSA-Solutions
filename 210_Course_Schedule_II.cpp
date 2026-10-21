#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> deg(numCourses, 0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            deg[it[0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it : adj[temp]){
                deg[it]--;
                if(deg[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        }

        return ans;
    }
};

int main()
{

    return 0;
}