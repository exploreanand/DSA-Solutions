#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    void backtracking(vector<string> &board, int row, int n, vector<int> &col, vector<int> &dia, vector<int> &antidia){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            
            int d = row - c + n - 1;
            int ad = row + c;
            
            if(col[c] || dia[d] || antidia[ad]){
                continue;
            }

            col[c] = dia[d] = antidia[ad] = 1;
            board[row][c] = 'Q';

            backtracking(board, row + 1, n, col, dia, antidia);

            col[c] = dia[d] = antidia[ad] = 0;
            board[row][c] = '.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0);
        vector<int> dia(2*n-1, 0);
        vector<int> antidia(2*n-1, 0);

        backtracking(board, 0, n, col, dia, antidia);
        
        return res;
    }
};

int main()
{

    return 0;
}