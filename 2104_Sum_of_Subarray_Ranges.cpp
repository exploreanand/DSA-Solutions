#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> min_left, min_right;
    vector<int> max_left, max_right;
    stack<int> st;

    void pre_min(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                min_left[i]= -1;
            }
            else{
                min_left[i] = st.top();
            }
            st.push(i);
        }
    }

    void post_min(vector<int>& nums){
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] <= nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                min_right[i] = n;
            }
            else{
                min_right[i]=st.top();
            }
            st.push(i);
        }
    }

    void pre_max(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                max_left[i] = -1;
            }
            else{
                max_left[i]= st.top();
            }
            st.push(i);
        }
    }
    void post_max(vector<int>& nums){
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(st.empty()){
                max_right[i] = n;
            }
            else{
                max_right[i]= st.top();
            }
            st.push(i);
        }
    }
    void clearStack(){
        while(!st.empty()){
            st.pop();
        }
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        min_left.resize(n);
        max_left.resize(n);
        min_right.resize(n);
        max_right.resize(n);

        pre_min(nums);
        clearStack();

        pre_max(nums);
        clearStack();

        post_min(nums);
        clearStack();

        post_max(nums);
        clearStack();

        long long maxSum = 0;
        long long minSum = 0;
        
        for(int i = 0; i < n; i++){
            long long total = 0;
            total = (1LL * nums[i]) * (i - min_left[i]) * (min_right[i] - i);
            minSum += total;
        }

        for(int i = 0; i < n; i++){
            long long total = 0;
            total = (1LL * nums[i]) * (i - max_left[i]) * (max_right[i] - i);
            maxSum += total;
        }

        return (maxSum - minSum);
    }
};

int main()
{

    return 0;
}