#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string str = to_string(x);
        int size = str.length();

        for (int i = 0; i <= size / 2; i++)
        {
            if (str[i] != str[size - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;

    if (obj.isPalindrome(1000021))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;

    return 0;
}