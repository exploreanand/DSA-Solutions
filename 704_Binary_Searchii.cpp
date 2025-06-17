#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low<high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid]== target)
            {
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
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