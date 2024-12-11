#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1)/2;
        for (int i = 0; i < n; i++){
            sum -= nums[i];
        }
        return sum;
    }
};
int main()
{
    Solution solution;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    cout << solution.missingNumber(nums) << endl;
    return 0;
}