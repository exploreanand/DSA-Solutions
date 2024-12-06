#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        int temp = 0;
        for (int i = 0; i < n; i++){
            if (nums[i]==1){
                temp++;
            }
            else{
                max = max > temp ? max : temp;
                temp = 0;
            }
        }
        max = max > temp ? max : temp;
        return max;
    }
};
int main()
{
    vector<int> numb;

    numb.push_back(1);
    numb.push_back(1);
    numb.push_back(0);
    numb.push_back(1);
    numb.push_back(1);
    numb.push_back(1);

    Solution s;
    cout<<s.findMaxConsecutiveOnes(numb)<<endl;
    return 0;
}