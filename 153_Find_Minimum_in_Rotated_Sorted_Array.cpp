#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[high]){
                return nums[low];
            }
            else{
                if(nums[low] <= nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid;
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}