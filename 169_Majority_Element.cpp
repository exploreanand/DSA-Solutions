// Moore Voting Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;int candi;int i=0;
        while (i<nums.size()){
            if (count == 0){candi=nums[i];}
            nums[i]==candi?count++:count--;
            i++;
        }
        return candi;
    }
};
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    cout<<s.majorityElement(nums);
    
    return 0;
}