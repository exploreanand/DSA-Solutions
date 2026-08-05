#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> st;
    vector<int> min_index;
    vector<int> max_index;

    void pre(vector<int>& arr, int n){
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                min_index[i] = -1;
            }
            else{
                min_index[i] = st.top();
            }
            st.push(i);
        }
    }

    void post(vector<int>& arr, int n){
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                max_index[i] = n;
            }
            else
                max_index[i] = st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        min_index.resize(n);
        max_index.resize(n);
        pre(arr, n);
        while(!st.empty()){
            st.pop();
        }
        post(arr, n);
        long long ans = 0;
        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int left = i - min_index[i];
            int right = max_index[i] - i;

            long long total = 1LL * left * right;
            total = (total * arr[i])%mod;
            ans = (ans + total)%mod;
        }
        return (int)ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    long long sol = obj.sumSubarrayMins(arr);
    cout<<sol<<endl;

    return 0;
}