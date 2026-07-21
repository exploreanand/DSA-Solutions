#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> res;
    void backtracking(string &num, int target, int index, long long value, string exp, long long last_operand){
        if(index == num.size()){
            if(value == target){
                res.push_back(exp);
            }
            return;
        }
        long long curr_val = 0;
        for(int i = index; i < num.size(); i++){
            if(i > index && num[index]=='0'){
                break;
            }
            curr_val = curr_val*10 + (num[i] - '0');
            string curr_str = num.substr(index, i - index + 1);

            if(index == 0){
                backtracking(num, target, i + 1, curr_val, curr_str, curr_val);
            }
            else{
                // +
                backtracking(num, target, i+1, value + curr_val, exp + "+" + curr_str, curr_val);
                // -
                backtracking(num, target, i+1, value  - curr_val, exp + "-" + curr_str, -curr_val);
                // *
                backtracking(num, target, i+1, (value - last_operand) + last_operand * curr_val, exp + "*" + curr_str, last_operand * curr_val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtracking(num, target, 0, 0, "", 0);
        return res;
    }
};

int main()
{

    return 0;
}