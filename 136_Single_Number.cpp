#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result=result^nums[i];
            cout<<result<<endl;
        }
        
        return result;
    }
};
int main()
{
    vector<int> numb;

    numb.push_back(6);
    numb.push_back(2);
    numb.push_back(1);
    numb.push_back(3);
    numb.push_back(2);
    numb.push_back(1);
    numb.push_back(3);

    Solution s;
    // cout<<s.singleNumber(numb)<<endl;
    int r;
    r=6^3;
    cout<<r;
    return 0;
}