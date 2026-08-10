#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largest_area(vector<int>& height){
        int n = height.size();
        vector<int> pse;
        vector<int> nse;
        pse.resize(n);
        nse.resize(n);
        stack<int> st;

        // pse
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[i] < height[st.top()]){
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
        while(!st.empty()){
            st.pop();
        }
        // nse
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && height[i] <= height[st.top()]){
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

        int largest_area = 0;
        for(int i = 0; i < n; i++){
            int area = height[i] * (nse[i] - pse[i] -1);
            largest_area = (area > largest_area)? area : largest_area;
        }
        return largest_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height;
        height.resize(m, 0);

        int largest_rectangle = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j]++;
                }
            }

            largest_rectangle = max(largest_rectangle , largest_area(height));
        }
        return largest_rectangle;
    }
};

int main()
{

    return 0;
}