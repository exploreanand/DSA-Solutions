#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> intervals;
    intervals = {{1,3}, {2,5}, {6,9}, {3,5}};
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    cout<<n;
    return 0;
}