#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        vector<int> ch(3, 0);

        int i = 0;
        int j = 0;

        long long invalid_subs = 0;

        while(j < n){
            ch[s[j] - 'a']++;

            while(ch[0] > 0 && ch[1] > 0 && ch[2] > 0){
                ch[s[i] - 'a']--;
                i++;
            }

            invalid_subs += (j - i + 1);
            j++;
        }
        long long total = 1LL * n * (n+1)/2;
        return total - invalid_subs;
    }
};

// Cleaner Solution

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ch[3] = {-1, -1, -1};
        int ans = 0;

        for(int j = 0; j < n; j++){
            ch[s[j] - 'a'] = j;
            
            if(ch[0] != -1 && ch[1] != -1 && ch[2]!= -1){
                ans += min({ch[0], ch[1], ch[2]}) + 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}