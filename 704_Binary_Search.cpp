// Binary Search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size();
        if (target == nums[n/2]){
            return n/2;
        }
        else if (target < nums[n/2])
        {
            vector<int> left(nums.begin(),nums.begin()+n/2);
            return search(left, target);
        }
        else 
        {
            vector<int> right(nums.begin()+(n/2)+1 , nums.end());
            int res = search(right, target); 
            return res == -1 ? -1 : n/2 + 1 + res;          // Add n/2 which was subtracted, to not lose index.
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    cout<<obj.search(nums, target)<<endl;
    return 0;
}