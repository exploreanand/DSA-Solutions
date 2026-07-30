#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        int l = 0;
        int n = height.size();
        int r = n - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(left_max < height[l]){
                    left_max = height[l];
                    l++;
                    continue;
                }
                ans += left_max - height[l];
                l++;
            }
            else{
                if(right_max < height[r]){
                    right_max = height[r];
                    r--;
                    continue;
                }
                ans += right_max - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}