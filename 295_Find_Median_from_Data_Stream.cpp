#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> l_half;
    priority_queue<int, vector<int>, greater<int>> r_half;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l_half.empty() || num <= l_half.top()){
            l_half.push(num);
        }
        else
            r_half.push(num);
        
        if(r_half.size() > l_half.size()){
            l_half.push(r_half.top());
            r_half.pop();
        }
        else if(l_half.size() > r_half.size() + 1){
            r_half.push(l_half.top());
            l_half.pop();
        }
    }
    
    double findMedian() {
        double median = 0;
        if(l_half.size() > r_half.size()){
            median = l_half.top();
        }
        else{
            median = (l_half.top() + r_half.top())/2.0;
        }
        return median;
    }
};

int main()
{

    return 0;
}