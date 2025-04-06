#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1) return;

        int j = n - 1;
        while (j > 0 && nums[j] <= nums[j - 1]) {
            j--;
        }

        if (j == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int tar = j - 1;

        int k = n - 1;
        while (nums[k] <= nums[tar]) {
            k--;
        }

        swap(nums[tar], nums[k]);

        reverse(nums.begin() + j, nums.end());
    }
};
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(2);
    // nums.push_back(1);
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}