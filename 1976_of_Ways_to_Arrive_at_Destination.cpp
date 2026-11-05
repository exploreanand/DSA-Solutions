#include <iostream>
#include <queue>
using namespace std;

class Solution {
    using pli = pair<long long, int>;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        // Preparing Adj list (Two way exist)
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        // Initialised dist array
        vector<long long> dist(n, 1e18);
        vector<int> no_path(n, 0);

        // {dist, node}
        priority_queue<pli, vector<pli>, greater<pli>> pq;

        // Insert source manually
        pq.push({0, 0});
        no_path[0] = 1;
        dist[0] = 0;

        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > dist[node]) continue;

            for(auto it : adj[node]){
                int adj_cost = it.first;
                int adj_node = it.second;
                long long new_cost = cost + adj_cost;

                if(cost + adj_cost < dist[adj_node]){
                    dist[adj_node] = cost + adj_cost;
                    no_path[adj_node] = no_path[node];
                    pq.push({cost + adj_cost, adj_node});
                }
                else if(cost + adj_cost == dist[adj_node]){
                    no_path[adj_node] = (no_path[node] + no_path[adj_node]) % MOD;
                }
            }
        }

        return no_path[n-1];
    }
};

int main()
{

    return 0;
}