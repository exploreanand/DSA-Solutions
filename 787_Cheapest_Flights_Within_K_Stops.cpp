#include <iostream>
#include <queue>
using namespace std;

class Solution {
    // {stops, {node, distance}}
    using pi = pair<int, pair<int, int>>;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);
        queue<pi> q;

        // {stops, {node, distance}}
        dist[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            int st = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(st > k) continue;

            for(auto i : adj[node]){
                int adj_node = i.first;
                int edge_w = i.second;

                if(cost + edge_w < dist[adj_node]){
                    dist[adj_node] = cost + edge_w;
                    q.push({st+1, {adj_node, cost + edge_w}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main()
{

    return 0;
}