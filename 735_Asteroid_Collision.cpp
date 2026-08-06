#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int asteroid : asteroids){
            bool destroyer = false;
            while(!st.empty() && asteroid < 0 && st.top() > 0){
                if(abs(asteroid) > st.top()){
                    st.pop();
                }
                else if(abs(asteroid) == st.top()){
                    st.pop();
                    destroyer = true;
                    break;
                }
                else{
                    destroyer = true;
                    break;
                }
            }
            if(!destroyer){
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}