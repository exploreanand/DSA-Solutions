#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n){
            return "0";
        }
        int k_val = k;
        stack<char> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && num[i] < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k != 0){
            st.pop();
            k--;
        }
        string ans;
        ans.resize(n-k_val);
        int i = 0;
        while(!st.empty()){
            ans[n-k_val-1-i] = st.top();
            st.pop();
            i++;
        }

        int pos = 0;
        while(pos < ans.size() && ans[pos] == '0'){
            pos++;
        }
        ans = ans.substr(pos);

        return ans.empty()? "0" : ans;
    }
};

int main()
{

    return 0;
}