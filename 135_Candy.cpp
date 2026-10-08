#include <iostream>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        int ans = 1;
        int i = 1;
        int peak = 1;
        int down = 0;
        int n = ratings.size();

        while(i < n){
            while(i < n && ratings[i] == ratings[i-1]){
                ans += 1;
                i++;
                continue;
            }
            peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                ans = ans + peak;
                i++;
            }
            down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                ans = ans + down;
                down++;
                i++;
            }
            if(down > peak){
                ans = ans + (down - peak);
            }
        }
        return ans;

        return ans;
    }
};

int main()
{

    return 0;
}