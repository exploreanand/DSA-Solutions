#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        string ans;
        ans.reserve(s.size());

        int counter = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (counter > 0)
                {
                    ans += ch;
                }
                counter++;
            }
            else{
                counter--;
                if(counter > 0){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}