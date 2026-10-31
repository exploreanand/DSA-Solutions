#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mpp;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i : hand){
            mpp[i]++;
        }

        for(auto& [card, count] : mpp){
            pq.push(card);
        }

        while(!pq.empty()){
            if(mpp[pq.top()] == 0){
                pq.pop();
                continue;
            }
            int start = pq.top();
            for(int i = 0; i < groupSize; i++){
                if(mpp[start] == 0) return false;
                mpp[start]--;
                start = start + 1;
            }
        }

        return true;
    }
};