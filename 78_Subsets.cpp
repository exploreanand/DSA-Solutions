#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int num = 0; num < (1 << n); num++){
            vector<int> sol;
            for(int i = 0; i < n; i++){
                if(num & (1<<i)){
                    sol.push_back(nums[i]);
                }
            }
            res.push_back(sol);
        }
        return res;
    }
};

int main()
{

    return 0;
}