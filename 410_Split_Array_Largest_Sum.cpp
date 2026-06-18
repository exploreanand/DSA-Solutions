#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool k_accomodates(vector<int>& nums, int k, long long mid){
        long long currSum = 0;
        int subarrays = 1;

        for(int num : nums){
            if((currSum + num)<=mid){
                currSum += num;
            }
            else{
                subarrays++;
                currSum = num;
            }
        }
        return subarrays<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low<=high){
            long long mid = low + (high - low)/2;
            if(k_accomodates(nums, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{

    return 0;
}