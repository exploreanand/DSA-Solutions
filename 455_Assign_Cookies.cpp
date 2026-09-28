#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        int g_size = g.size();
        int s_size = s.size();

        while(i < g_size && j < s_size){
            if(g[i] <= s[j]){
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return min(i , j);
    }
};

int main()
{

    return 0;
}