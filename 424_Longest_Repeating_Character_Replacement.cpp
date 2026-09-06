#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int freq[26] = {0};
        int i = 0;
        int j = 0;

        int m_len = 0;
        int m_freq = 0;

        while(j < n){
            freq[s[j] - 'A']++;
            m_freq = max(m_freq, freq[s[j] - 'A']);
            
            while((j - i + 1) - m_freq > k){
                freq[s[i] - 'A']--;
                i++;
            }
            m_len = max(m_len, j - i + 1);
            j++;
        }
        return m_len;
    }
};

int main()
{

    return 0;
}