#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU{
private:
    vector<int> parents;
    vector<int> size;
public:
    DSU(int n){
        parents.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parents[i] = i;
        }
    }

    int find(int a){
        if(parents[a] == a) return a;
        return parents[a] = find(parents[a]);
    }
    void merge(int u, int v){
        int root_u = find(u); 
        int root_v = find(v);

        if(root_u != root_v){
            if(size[root_u] < size[root_v]){
                parents[root_u] = root_v;
                size[root_v] += size[root_u];
            }
            else{
                parents[root_v] = root_u;
                size[root_u] += size[root_v];
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mapp;
        int n = accounts.size();
        DSU obj(n);

        for(int i = 0; i < n; i++){
            int m = accounts[i].size();
            for(int j = 1; j < m; j++){
                auto it = mapp.find(accounts[i][j]);
                if(it == mapp.end()){
                    mapp[accounts[i][j]] = i;
                }
                else{
                    obj.merge(i, it->second);
                }
            }
        }

        vector<vector<string>> ans(n);
        for(const auto& it : mapp){
            string mail = it.first;
            int root = obj.find(it.second);
            ans[root].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(ans[i].empty()) continue;
            sort(ans[i].begin(), ans[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), ans[i].begin(), ans[i].end());
            res.push_back(move(temp));
        }

        return res;
    }
};


int main()
{

    return 0;
}