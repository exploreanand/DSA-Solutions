#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(string curr, int open, int close, int n, vector<string>& res){
        
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }

        if(open<n){
            backtracking(curr+'(', open+1, close, n, res);
        }
        if(close<open){
            backtracking(curr+')', open, close+1, n, res);
        }

    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;

        backtracking("", 0, 0, n, res);
        return res;
    }
};

int main()
{

    return 0;
}