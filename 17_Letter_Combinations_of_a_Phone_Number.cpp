#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    unordered_map<char , string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtracking(string &digit, string &curr, int index){
        if(index == digit.size()){
            res.push_back(curr);
            return;
        }

        string letters = mp[digit[index]];

        for(char ch : letters){
            curr.push_back(ch);
            backtracking(digit, curr, index+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string curr;
        backtracking(digits, curr, 0);

        return res;
    }
};

int main()
{

    return 0;
}