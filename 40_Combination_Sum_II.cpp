#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& curr, int index, vector<int>& candidates, int target, vector<vector<int>>& res){
        
        if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            if(candidates[i] > target){break;}
            curr.push_back(candidates[i]);
            backtracking(curr, i + 1, candidates, target - candidates[i], res);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtracking(curr, 0, candidates, target, res);
        return res;
    }
};

int main()
{

    return 0;
}