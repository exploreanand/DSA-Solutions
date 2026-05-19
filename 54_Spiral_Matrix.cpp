#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int row = matrix.size();
        int column = matrix[0].size();
        
        
        int left = 0;
        int right = column - 1;
        int top = 0;
        int bottom = row - 1;
        int prints = 0;

        while(top<=bottom && left<=right){

            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left<=right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main() { 
    Solution obj; 
    vector<int> ans; 
    vector<vector<int>> matrix(3, vector<int>(3, 0)); 
    
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; 
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6; 
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9; 
    
    ans = obj.spiralOrder(matrix); 
    
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0; 
}