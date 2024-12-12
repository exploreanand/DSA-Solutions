// Kadane's Algorithm
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr; int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if (curr<0){curr=0;}
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> v1;
    v1.push_back(-2);
    v1.push_back(1);
    v1.push_back(-3);
    v1.push_back(4);
    v1.push_back(-1);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(-5);
    v1.push_back(4);
    cout<<s.maxSubArray(v1)<<endl;

    return 0;
}