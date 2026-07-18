#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string &word, int w_index, int i, int j){
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return false;
        }
        if(board[i][j] == '#'){
            return false;
        }
        if(word[w_index] != board[i][j]){
            return false;
        }
        if(w_index == word.size() - 1){
            return true;
        }


        char temp = board[i][j];
        board[i][j] = '#';

        w_index += 1;

        bool found = backtracking(board, word, w_index, i - 1, j) || backtracking(board, word, w_index, i + 1, j) || backtracking(board, word, w_index, i, j - 1) || backtracking(board, word, w_index, i, j + 1);
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    if(backtracking(board, word, 0, i, j)){
                        return true;
                    }
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