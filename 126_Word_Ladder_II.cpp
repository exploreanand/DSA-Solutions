#include <iostream>
using namespace std;

class Solution {
    void dfs(string curr, vector<string> &curr_list, string &beginWord, unordered_map<string, vector<string>> &parent, vector<vector<string>> &ans)
    {
        if(curr == beginWord){
            vector<string> path = curr_list;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }

        for(const auto &it : parent[curr]){
            curr_list.push_back(it);
            dfs(it, curr_list, beginWord, parent, ans);
            curr_list.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        if (beginWord == endWord) return {{beginWord}};
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.contains(endWord)) return {};
        unordered_map<string, int> mpp;
        unordered_map<string, vector<string>> parent;
        vector<vector<string>> ans;
        vector<string> curr_list;
        
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        int endLevel = INT_MAX;

        while(!q.empty()){
            string temp = q.front();
            string word = temp;
            int lvl = mpp[temp];
            int n = temp.size();
            q.pop();
            if (lvl >= endLevel) break;

            if (temp == endWord) {
                endLevel = lvl;
                continue;
            }

            for(int i = 0; i < n; i++){
                char original = temp[i];
                for(char j = 'a'; j <= 'z'; j++){
                    temp[i] = j;
                    if(st.contains(temp)){
                        if (!mpp.count(temp)) {
                            mpp[temp] = lvl + 1;
                            parent[temp].push_back(word);
                            q.push(temp);
                        }
                        else if (mpp[temp] == lvl + 1) {
                            parent[temp].push_back(word);
                        }
                    }
                }
                temp[i] = original;
            }
        }
        curr_list.push_back(endWord);
        dfs(endWord, curr_list, beginWord, parent, ans);
        return ans;
    }
};

int main()
{

    return 0;
}