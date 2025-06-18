#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                if (low==high)
                {
                    return mid;
                }
                else{
                    high = mid;
                }
            }
            else if (target > nums[mid])
            {
                if (low==high)
                {
                    return mid+1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3};
    cout<<obj.searchInsert(nums, 0)<<endl;
    return 0;
}