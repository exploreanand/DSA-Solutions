#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_len = matrix.size();
        int col_len = matrix[0].size();

        int low = 0;
        int high = row_len - 1;
        int target_row = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[mid][0] <= target && target <= matrix[mid][col_len - 1]){
                target_row = mid;
                break;
            }
            else{
                if(matrix[mid][0] > target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        if(target_row == -1){
            return false;
        }
        
        low = 0;
        high = col_len - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(matrix[target_row][mid] == target){
                return true;
            }
            else{
                if(matrix[target_row][mid] < target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
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