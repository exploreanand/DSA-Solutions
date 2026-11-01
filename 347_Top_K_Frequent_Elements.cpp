#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int & i : nums){
            freq[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto& it: freq){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(k > 0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

int main()
{

    return 0;
}