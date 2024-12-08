#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        for (int iter = 0; iter < n; iter++){
            if (nums[iter]==0){
                i++;
            }
            else if(nums[iter]==1){
                j++;
            }
        }
        for (int iter = 0; iter < n; iter++){
            if (i>0){
                nums[iter]=0;
                i--;
            }
            else if(i==0 && j>0){
                nums[iter]=1;
                j--;
            }
            else{
                nums[iter]=2;
            }
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