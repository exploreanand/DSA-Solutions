#include <iostream>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> first_sort;
        vector<int> second_sort;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            first_sort.push_back(intervals[i][0]);
            second_sort.push_back(intervals[i][1]);
        }
        
        sort(first_sort.begin(), first_sort.end());
        sort(second_sort.begin(), second_sort.end());

        int j = 0;
        int k = 0;
        int count = 0;
        int ans = 0;
        while(j < n){
            if(first_sort[j]<=second_sort[k]){
                count++;
                ans = max(ans, count);
                j++;
            }
            else{
                count--;
                k++;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}