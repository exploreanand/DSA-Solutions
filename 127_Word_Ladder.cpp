#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordList_set(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        int level = 1;
        q.push({beginWord, level});

        while(!q.empty()){
            string temp = q.front().first;
            int lvl = q.front().second;
            q.pop();
            int n = temp.size();
            for(int i = 0; i < n; i++){
                string new_str = temp;
                for(int j = 0; j < 26; j++){
                    char new_char = 'a' + j;
                    new_str[i] = new_char;
                    if(wordList_set.contains(new_str)){
                        if(new_str == endWord){
                            return lvl + 1;
                        }
                        q.push({new_str, lvl + 1});
                        wordList_set.erase(new_str);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}