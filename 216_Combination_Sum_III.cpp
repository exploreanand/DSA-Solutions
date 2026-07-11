#include <iostream>
using namespace std;

class Solution
{
public:

    void backtracking(vector<vector<int>> &res, vector<int> &curr, int k, int remain, int start){
        
        if(curr.size() == k){
            if(remain == 0){
                res.push_back(curr);
            }
            return;
        }

        for(int i = start; i < 10; i++){
            if(i > remain){break;}
            curr.push_back(i);
            backtracking(res, curr, k, remain - i, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(res, curr, k, n, 1);
        return res;
    }
};

int main()
{

    return 0;
}