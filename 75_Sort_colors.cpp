#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0;int m=0;int r=n-1;
        while(m<=r){
            if(nums[m]==0){swap(nums[l],nums[m]);l++;m++;}
            else if(nums[m]==1){m++;}
            else{swap(nums[m],nums[r]);r--;}
        }
    }
};
int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
        }
    return 0;
}