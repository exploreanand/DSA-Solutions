#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        int j = 0;
        for(int i = 1; i < strs.size(); i++){
            j = 0;
            while(j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]){
                j++;
            }

            prefix.resize(j);

            if(prefix.empty()){
                return "";
            }
        }
        return prefix;
    }
};

int main()
{

    return 0;
}
