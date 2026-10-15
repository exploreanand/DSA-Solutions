#include <iostream>
using namespace std;

class LockingTree {
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockedBy;

    void dfs(int node, vector<int> &locked_decendents){
        for(int child : children[node]){
            if(lockedBy[child] != 0){
                locked_decendents.push_back(child);
            }
            dfs(child, locked_decendents);
        }
    }

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        children.resize(n);
        lockedBy.assign(n, 0);

        for(int i = 0; i < n; i++){
            if(parent[i] != -1){
                children[parent[i]].push_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if(lockedBy[num] != 0){
            return false;
        }
        lockedBy[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(lockedBy[num] == user){
            lockedBy[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(lockedBy[num] != 0) return false;

        // Checking ancestors
        int cur = parent[num];
        while(cur != -1){
            if(lockedBy[cur] != 0){
                return false;
            }
            cur = parent[cur];
        }

        // Checking decendents
        vector<int> locked_decendents;
        dfs(num, locked_decendents);

        if(locked_decendents.empty()){
            return false;
        }
        for (int node : locked_decendents) {
            lockedBy[node] = 0;
        }
        lockedBy[num] = user;

        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
int main()
{

    return 0;
}