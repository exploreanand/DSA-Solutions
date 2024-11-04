#include <iostream>
#include <string>
using namespace std;
class my_stack
{
public:
    int length;
    int top;
    char *arr;

    my_stack(int size)
    {
        length = size;
        top = -1;
        arr = new char[length];
    }
};

class Solution
{
public:
    bool isValid(string s)
    {
        int count = s.length();
        my_stack obj(count);

        for (int i = 0; i < count; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                obj.top += 1;
                obj.arr[obj.top] = s[i];
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (obj.top != -1)
                {
                    if (obj.arr[obj.top] == '(' && s[i] == ')' || obj.arr[obj.top] == '{' && s[i] == '}' || obj.arr[obj.top] == '[' && s[i] == ']')
                    {
                        obj.top -= 1;
                    }
                    else
                    return false;
                }
                else
                return false;
            }
        }
        if (obj.top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    if (obj.isValid(s))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;

    return 0;
}