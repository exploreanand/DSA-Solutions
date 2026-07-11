#include <iostream>
using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>>& res, int index, vector<int>& curr, vector<int>& nums){
        
        res.push_back(curr);

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }
            curr.push_back(nums[i]);
            
            backtracking(res, i + 1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(res, 0, curr, nums);
        return res;
    }
};

int main()
{

    return 0;
}