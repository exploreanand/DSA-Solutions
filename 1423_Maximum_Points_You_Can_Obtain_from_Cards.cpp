#include <iostream>
using namespace std;

// My Solution with circular window
// Time Complexity O(2k)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int t_window = 2*k;

        int i = n - k;
        int j = i;
        int z = 0;
        int sum = 0;
        int k2 = k;
        int ans = 0;

        while(z < t_window){
            sum += cardPoints[j%n];
            k2--;
            if(k2 == 0){
                ans = max(ans, sum);
                sum = sum - cardPoints[i%n];
                k2++;
                i++;
            }
            j++;
            z++;
        }
        return ans;
    }
};

// Standard Solution O(n)

int main()
{

    return 0;
}