#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n-1; i++)
        {
            if (nums[i]<=nums[i+1])
            {
                continue;
            }
            else{
                count++;
            }
        }
        if (count==1)
        {
            if (nums[0]>=nums[n-1])
            {
                return true;
            }
            return false;
        }
        if (count<1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(9);
    Solution s;
    cout << s.check(nums) << endl;
    return 0;
}