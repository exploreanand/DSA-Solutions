#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row_len = mat.size();
        int col_len = mat[0].size();

        int low = 0;
        int high = row_len - 1;

        while(low <= high){
            int mid_row = low + (high - low)/2;
            int y = -1;
            int max_element = INT_MIN;
            for(int i = 0; i < col_len; i++){
                if(mat[mid_row][i] > max_element){
                    max_element = mat[mid_row][i];
                    y = i;
                }
            }

            int up = (mid_row > 0) ? mat[mid_row - 1][y]: -1;
            int down = (mid_row < row_len - 1) ? mat[mid_row + 1][y]: -1;

            if((max_element > up) && (max_element > down)){
                return {mid_row, y};
            }
            else{
                if((max_element < up)){
                    high = mid_row - 1;
                }
                else{
                    low = mid_row + 1;
                }
            }
        }

        return {-1 , -1};
    }
};

int main()
{

    return 0;
}