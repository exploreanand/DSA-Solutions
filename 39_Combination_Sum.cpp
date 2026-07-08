#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& curr, int curr_sum, int index, vector<int>& candidates, int target, vector<vector<int>>& res){
        
        if(curr_sum == target){
            res.push_back(curr);
            return;
        }

        if(index >= candidates.size() || curr_sum > target){
            return;
        }

        curr.push_back(candidates[index]);
        backtracking(curr, curr_sum + candidates[index], index, candidates, target, res);

        curr.pop_back();

        backtracking(curr, curr_sum, index + 1, candidates, target, res);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(curr, 0, 0, candidates, target, res);
        return res;
    }
};

int main()
{

    return 0;
}