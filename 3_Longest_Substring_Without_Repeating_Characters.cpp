#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){return 0;}
        vector<int> last(256, -1);

        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){
            i = max(i, last[s[j]] + 1);

            last[s[j]] = j;
                j++;

            int x = j - i;
            if(x > ans){
                ans = x;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}