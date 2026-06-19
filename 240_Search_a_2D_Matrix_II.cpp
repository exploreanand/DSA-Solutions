// Not a tipical Binary Search but we are still eliminating the rows or columns
// This is an optimal solution

#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix.size();
        int col_len = matrix[0].size();
        int row = 0;
        int column = col_len - 1;

        while( row < row_len && column >= 0){
            if(matrix[row][column] == target){
                return true;
            }
            else{
                if(matrix[row][column] > target){
                    column--;
                }
                else{
                    row++;
                }
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}