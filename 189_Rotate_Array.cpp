// Time Complexity O(nlog(n))
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
int main()
{
    vector<int> numb;
    numb.push_back(1);
    numb.push_back(2);
    numb.push_back(3);
    numb.push_back(4);
    numb.push_back(5);
    numb.push_back(6);
    numb.push_back(7);
    Solution s;
    s.rotate(numb, 13);
    for (int i = 0; i < numb.size(); i++)
    {
        cout << numb[i] << " ";
    }
    return 0;
}