#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int no : nums){
            pq.push(no);
            if(pq.size() > k) pq.pop();
        }
        
        return pq.top();
    }
};

int main()
{

    return 0;
}