#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main(){
    vector<int> nums;
    string s;
    cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
           nums.push_back(s[i]);
        }
    }
    cout<<nums.size()<<endl;
    cout<<nums.capacity()<<endl;
    return 0;
}