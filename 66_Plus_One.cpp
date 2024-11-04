#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count = digits.size();
        string str[count];
        string final,final2;

        for (int i = 0; i < count; i++)
        {
            str[i]=to_string(digits.at(i));
        }
        digits.clear();
        for (int j = 0; j < count; j++)
        {
            final += str[j];
        }
        int num;
        cout<<final<<endl;
        num = stoi(final);
        num+=1;
        final2=to_string(num);

        string gf[count+1];
        for (int l = 0; l < count+1; l++)
        {
            gf[l]=final2[l];
        }

        for (int k = 0; k < count+1; k++)
        {
            digits.push_back(stoi(gf[k]));
            cout<<stoi(gf[k])<<" Pushed"<<endl;
        }

        return digits;
    }
};

int main()
{
    Solution result;
    vector<int> obj;
    vector<int> out;
    obj.push_back(9);

    out=result.plusOne(obj);
    for (int i = 0; i < 10; i++)
    {
        cout<<out.at(i)<<endl;
    }

    return 0;
}