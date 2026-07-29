#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 52709
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i % n])
            {
                s.pop();
            }
            if (i < n)
            {
                if (s.empty())
                {
                    ans[i] = -1;
                }
                else
                    ans[i] = s.top();
            }

            s.push(nums[i % n]);
        }
        return ans;
    }
};

// The Brute Force Solution
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j%n != i; j++){
//                 if(nums[i] < nums[j%n]){
//                     ans.push_back(nums[j%n]);
//                     break;
//                 }
//             }
//             if(ans.size() == i){
//                 ans.push_back(-1);
//             }
//         }
//         return ans;
//     }
// };

int main()
{

    return 0;
}