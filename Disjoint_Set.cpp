#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i <= n; i++){
           parent[i] = i;
        }
        size.resize(n+1, 1);
    }
    int findParent(int a){
        if(parent[a] == a) return a;

        return parent[a] = findParent(parent[a]);
    }

    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void unionByRank(int u, int v) {
        int u_parent = findParent(u);
        int v_parent = findParent(v);
        if(u_parent == v_parent) return;
        
        if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }
        else if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }
        else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    void unionBySize(int u, int v) {
        int u_parent = findParent(u);
        int v_parent = findParent(v);
        if(u_parent == v_parent) return;
        
        if(size[u_parent] > size[v_parent]){
            parent[v_parent] = u_parent;
            size[u_parent] += size[v_parent];
        }
        else{
            parent[u_parent] = v_parent;
            size[v_parent] += size[u_parent];
        } 
        
    }
};


int main()
{

    return 0;
}