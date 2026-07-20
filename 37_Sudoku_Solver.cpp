#include <iostream>
using namespace std;

class Solution
{
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    bool solve(vector<vector<char>> &board)
    {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    continue;           // This Continue is very crucial
                }
                int b = (i / 3) * 3 + (j / 3);
                for(char ch = '1'; ch <= '9'; ch++){
                    int num = ch - '0';
                    if(
                        row[i][num] ||
                        col[j][num] ||
                        box[b][num]
                    ){
                        continue;       // This Continue is very crucial
                    }

                    board[i][j] = ch;
                    row[i][num] = true;
                    col[j][num] = true;
                    box[b][num] = true;
                    if(solve(board)){
                        return true;
                    }
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    box[b][num] = false;
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0';
                int b = (i / 3) * 3 + (j / 3);

                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }
        solve(board);
    }
};

int main()
{

    return 0;
}