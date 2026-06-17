#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    bool can_ship(vector<int>& weights, int ship_capacity, int required_days){
        int days = 1;
        int capacity = ship_capacity;
        for(int weight : weights){
            if(weight<=capacity){
                capacity -= weight;
            }
            else{
                days++;
                capacity = ship_capacity - weight;
            }
        }
        return days<=required_days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while(low<high){
            int mid = low + (high - low)/2;
            if(can_ship(weights, mid, days)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{

    return 0;
}