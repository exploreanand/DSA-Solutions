#include <iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                if(min < max && min == 0){
                    max--;
                    continue;
                }
                min--;
                max--;
            }
            else{
                if((min - 1) >= 0){
                    min--;
                }
                max++;
            }
            if(min < 0 || max < 0){return false;}
        }
        return (min == 0);
    }
};

int main()
{

    return 0;
}