#include <iostream>
using namespace std;

class Solution {
public:
    bool accepted_divisor(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += ((long long)nums[i]+mid-1)/mid;
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low<high){
            int mid = low + (high - low)/2;
            if(accepted_divisor(nums, threshold,mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{

    return 0;
}