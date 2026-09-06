#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.size() == 0){return 0;}
        int n = nums.size();

        int i = 0;
        int j = 0;
        int ans = 0;
        int ex = k;

        while(j < n){
            if(nums[j] != 1 && ex == 0){
                if(nums[i] == 0){
                    ex++;
                }
                i++;
            }
            else{
                if(nums[j] != 1){
                    ex--;
                }
                j++;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}