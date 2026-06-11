#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 0; i<n; i++){
            if(intervals[i][0]<=end){
                if(intervals[i][1]>end){
                    end = intervals[i][1];
                    continue;
                }
                continue;
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};

int main()
{

    return 0;
}