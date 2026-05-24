#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix_sum;
        int sum = 0;
        int counter = 0;
        prefix_sum[0]=1;
        for(int i = 0; i<n;i++){
            sum += nums[i];
            if(prefix_sum.find(sum - k) != prefix_sum.end()){
                counter += prefix_sum[sum-k];
            }
            prefix_sum[sum]++;;
        }
        return counter;
    }
};


int main()
{   Solution obj;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(-2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(-11);

    cout<<obj.subarraySum(nums, 6);

    return 0;
}