// Cancel out each-other and element with highest frequency remains.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count_1 = 0; int count_2 = 0;
        int ele_1 = 0; int ele_2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(count_1==0 && nums[i]!=ele_2){
                ele_1 = nums[i];
                count_1++;
            }
            else if(count_2==0 && nums[i]!=ele_1){
                ele_2 = nums[i];
                count_2++;
            }
            else if(nums[i]==ele_1){
                count_1++;
            }
            else if(nums[i]==ele_2){
                count_2++;
            }
            else{
                count_1--;count_2--;
            }
        }
        // Verification step
        count_1 = 0;
        count_2 = 0;

        for (int num : nums) {
            if (num == ele_1) count_1++;
            else if (num == ele_2) count_2++;
        }

        vector<int> ans;

        if (count_1 > nums.size() / 3){
            ans.push_back(ele_1);
        }

        if (count_2 > nums.size() / 3){
            ans.push_back(ele_2);
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<int> test = {1,1,1,3,3,2,2,2};

    vector<int> ans = s.majorityElement(test);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}