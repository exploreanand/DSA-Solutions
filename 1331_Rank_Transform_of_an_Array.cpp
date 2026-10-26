#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int, int> mpp;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i : arr){
            pq.push(i);
        }

        int n = arr.size();
        int rank = 1;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            if(mpp.find(temp) == mpp.end()){
                mpp[temp] = rank;
                rank++;
            }
        }

        for(int j = 0; j < n; j++){
            ans[j] = mpp[ans[j]];
        }

        return ans;
    }
};

int main()
{

    return 0;
}