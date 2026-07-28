#include <iostream>
using namespace std;

class MinStack {
private:
    stack<long long> s;
    long long curr_min = LLONG_MAX;
public:
    MinStack() {
        
    }
    // The formula is : 2*value - prev_min = new_modified_value_to_store
    void push(int value) {
        if(s.empty()){
            curr_min = value;
            s.push(value);
        }
        else if(value < curr_min){
            s.push(2LL*value - curr_min);
            curr_min = value;
        }
        else{
            s.push(value);
        }
    }
    
    void pop() {
        if(s.top() < curr_min){
            curr_min = 2*curr_min - s.top();
        }
        s.pop();

        if(s.empty()){
            curr_min = LLONG_MAX;
        }
    }
    
    int top() {
        if(s.top() < curr_min){
            return curr_min;
        }
        return s.top();
    }
    
    int getMin() {
        return curr_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    return 0;
}