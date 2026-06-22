#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m){return false;}

        vector<int> count(26, 0);

        for(int i = 0; i < n; i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int x : count){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}