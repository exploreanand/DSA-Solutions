#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,char> forward_map;
        unordered_map<char,char> backward_map;

        for(int i = 0; i < s.size(); i++){
            if(forward_map.contains(s[i])){
                if(forward_map[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                forward_map[s[i]] = t[i];
            }

            if(backward_map.contains(t[i])){
                if(backward_map[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                backward_map[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}