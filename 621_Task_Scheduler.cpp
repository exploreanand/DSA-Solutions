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

// Optimal Solution - mathematically
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        for(auto tx : tasks){
            freq[tx - 'A']++;
        }

        int maxFreq = 0;
        int count = 0;
        for(int i : freq){
            if(i > 0){
                if(i > maxFreq){
                    maxFreq = i;
                    count = 1;
                }
                else if(i == maxFreq){
                    count++;
                }
            }
        }
        int intervals = (maxFreq - 1)*(n + 1) + count;
        intervals = max((int)tasks.size(), intervals);
        return intervals;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(auto tx : tasks){
            freq[tx - 'A']++;
        }
        priority_queue<int> pq;

        for(int i : freq){
            if(i > 0){
                pq.push(i);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()){
                int remain = pq.top();
                pq.pop();
                remain--;
                if(remain > 0){
                    q.push({remain, time + n + 1});
                }
            }
        }
        return time;
    }
};

int main()
{

    return 0;
}