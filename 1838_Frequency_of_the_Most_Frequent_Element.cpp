// Learnings: Sliding Window Technique

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end()); 
        long long sum = 0;
        int left = 0;
        int maxFreq = 1;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(((long long)nums[r]*(r - left + 1) - sum) > k){
                sum -= nums[left];
                left++;
            }
            maxFreq = max(maxFreq, (r - left + 1));
        }
        return maxFreq;
    }
};

int main()
{   vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(6);
    Solution s;
    cout<<s.maxFrequency(nums, 5);

    return 0;
}