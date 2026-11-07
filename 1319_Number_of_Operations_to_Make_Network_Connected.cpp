#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> parent;
public:
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int u, int v, int &components){
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v){
            parent[root_u] = root_v;
            components--;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int components = n;
        for(const auto& connect : connections){
            unite(connect[0], connect[1], components);
        }
        return components - 1;
    }
};

int main()
{

    return 0;
}