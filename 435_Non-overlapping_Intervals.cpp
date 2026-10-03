#include <iostream>
using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int remove = 0;
        
        sort(intervals.begin(), intervals.end(), compare);
        int last_end = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] < last_end){
                remove++;
            }
            else{
                last_end = intervals[i][1];
            }
        }
        return remove;
    }
};

int main()
{

    return 0;
}