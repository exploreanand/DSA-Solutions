#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i]!=nums[i-1])
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);

    cout<<s.removeDuplicates(nums)<<endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

  return 0;
}