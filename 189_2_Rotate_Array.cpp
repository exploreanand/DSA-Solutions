// Time Complexity O(n^2)
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            int temp = nums[n-1];
            for (int j = n-1; j != 0; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0]=temp;
        }
    }
};

int main()
{   vector<int> numb;
    numb.push_back(9);  
    numb.push_back(2);  
    numb.push_back(3);  
    numb.push_back(4);  
    numb.push_back(5);  
    Solution s;
    s.rotate(numb,3);
    for (int i = 0; i < numb.size(); i++)
    {
        cout<<numb[i]<<endl;
    }
    
    return 0;
}