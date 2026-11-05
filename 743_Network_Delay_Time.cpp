#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    using pi = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjagency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({w, v});
        }

        // Track time to reach every node
        vector<int> time(n+1, INT_MAX);

        // {time, node}
        priority_queue<pi , vector<pi>, greater<pi>> pq;

        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()){
            auto[tm, node] = pq.top();
            pq.pop();
            if(tm > time[node]) continue;
            for(auto local : adj[node]){
                int next_time = local.first;
                int next_node = local.second;
                int t_time = next_time + tm;
                if(t_time < time[next_node]){
                    time[next_node] = t_time;
                    pq.push({t_time, next_node});
                }
            }
        }
        int max_time = -1;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX) return -1;
            if(time[i] > max_time){
                max_time = time[i];
            }
        }
        return max_time;
    }
};

int main()
{

    return 0;
}