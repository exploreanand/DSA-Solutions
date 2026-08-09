#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> pse;
    vector<int> nse;
    stack<int> st;

    void find_pse(vector<int>& heights, int n){
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
    }
    
    void find_nse(vector<int>& heights, int n){
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        pse.resize(n);
        nse.resize(n);
        find_pse(heights, n);
        while(!st.empty()){
            st.pop();
        }
        find_nse(heights, n);

        int largest_area = 0;

        for(int i = 0; i < n; i++){
            int area = 0;
            area = heights[i] * (nse[i] - pse[i] - 1);
            
            if (area > largest_area){
                largest_area = area;
            }
        }
        return largest_area;
    }
};

int main()
{

    return 0;
}