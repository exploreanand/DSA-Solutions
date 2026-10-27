#include <iostream>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        vector<int> avl(26, 0);

        for(auto tx : tasks){
            freq[tx - 'A']++;
        }

        int remain = tasks.size();
        int time = 0;
        while(remain){
            int select = -1;
            for(int i = 0; i < 26; i++){
                if(freq[i] > 0 && avl[i] <= time){
                    if(select == -1 || freq[i] > freq[select]){
                        select = i;
                    }
                }
            }

            time++;
            if(select != -1){
                freq[select]--;
                avl[select] = time + n;
                remain--;
            }
        }
        return time;
    }
};

int main()
{

    return 0;
}