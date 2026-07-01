#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        string ans = s;
        bool neg = false;
        int n = ans.size();
        int i = 0;

        // Check and Removing the leading whitespace
        while(i < n && ans[i] == ' '){
            i++;
        }

        // Checking the '+' or '-'
        if(i < n && ans[i] == '-'){
            neg = true;
            i++;
        }
        else if(i < n && ans[i] == '+'){
            i++;
        }

        long long res = 0;
        while(i < n && 0 <= (ans[i] - '0') && (ans[i] - '0') <= 9){
            res = res * 10 + (ans[i] - '0');
            if(res >= 2147483648LL){
                return neg ? INT32_MIN : INT32_MAX;
            }
            i++;
        }

        return neg ? -res:res;
    }
};

int main()
{

    return 0;
}