#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            int h = 0;
            for (int j = 0; j < nums.size(); j++){
                if (j==i){
                    continue;
                }
                else if (nums[i]==nums[j]){
                    h+=1;
                    break;
                }
            }
            if (h==0){return nums[i];}
        }
        return -1;
    }
};
int main()
{
    vector<int> numb;

    numb.push_back(1);
    numb.push_back(1);
    numb.push_back(3);
    numb.push_back(6);
    numb.push_back(2);
    numb.push_back(3);
    numb.push_back(2);

    Solution s;
    cout<<s.singleNumber(numb)<<endl;
    return 0;
}