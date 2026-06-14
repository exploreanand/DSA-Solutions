#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target){
                high = mid -1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int upper_bound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n -1;
        int ans = n;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int ll = lower_bound(nums, target);

        if(ll == -1 || nums[ll]!=target){
            return {-1, -1};
        }

        int ul = upper_bound(nums, target)-1;
        ans.push_back(ll);
        ans.push_back(ul);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}