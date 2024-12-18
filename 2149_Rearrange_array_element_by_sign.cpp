#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int even = 0; int odd = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i]>0)
            {
                ans[even]=nums[i];even+=2;
            }
            else{
                ans[odd]=nums[i];odd+=2;
            }
            
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<int> nums;
    nums.push_back(28);
    nums.push_back(-41);
    nums.push_back(22);
    nums.push_back(-8);
    nums.push_back(46);
    nums.push_back(-37);
    nums.push_back(35);
    nums.push_back(-9);
    nums.push_back(18);
    nums.push_back(-6);
    nums.push_back(19);
    nums.push_back(-26);
    nums.push_back(-37);
    nums.push_back(-10);
    nums.push_back(-9);
    nums.push_back(15);
    nums.push_back(14);
    nums.push_back(31);
    nums = solution.rearrangeArray(nums);

    return 0;
}