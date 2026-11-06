#include <iostream>
using namespace std;

class Solution{
    // {wt, {node, parent}}
    using pi = pair<int, pair<int, int>>;
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, {0, -1}});

        vector<bool> isVis(V, 0);

        int sum = 0;
        vector<pair<int , int>> vertex;

        while(!pq.empty()){
            auto [wt, node_info] = pq.top();
            auto [node, parent] = node_info;
            pq.pop();

            if(isVis[node]) continue;
            isVis[node] = true;

            if(parent != -1){
                vertex.push_back({parent, node});
                sum += wt;
            }

            for(auto it : adj[node]){
                int n_node = it[0];
                int n_wt = it[1];

                if(!isVis[n_node]){
                    pq.push({n_wt, {n_node, node}});
                }
            }
        }

        return sum;
    }
};

int main()
{

    return 0;
}