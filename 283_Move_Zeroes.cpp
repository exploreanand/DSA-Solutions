#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i]!=0)
            {
                nums[c]=nums[i];
                c++;
            }
        }
        for (int i = c; i < n; i++)
        {
            nums[i]=0;
        }
    }   
};

int main()
{
    vector<int> numb;
    numb.push_back(0);
    numb.push_back(0);
    numb.push_back(1);
    numb.push_back(0);
    numb.push_back(0);
    numb.push_back(1);
    numb.push_back(0);

    Solution s;
    s.moveZeroes(numb);
    for (int i = 0; i < numb.size(); i++)
    {
        cout << numb[i] << " ";
    }

    return 0;
}