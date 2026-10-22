#include <iostream>
using namespace std;

class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adj(K);
        vector<int> inDeg(K, 0);
        for(int i = 1; i < N; i++){
            const string& first = dict[i - 1];
            const string& second = dict[i];

            int len1 = first.size();
            int len2 = second.size();

            int a = 0;
            while (a < len1 && a < len2 &&
                   first[a] == second[a]) {
                a++;
            }

            if(a == len1 || a == len2){
                if(len1 > len2) return "";
                continue;
            }

            int u = first[a] - 'a';
            int v = second[a] - 'a';

            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        for(int i = 0; i < K; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        string s;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            s += char(temp + 'a');
            for(auto it : adj[temp]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }
        if (s.size() != K) return "";
        return s;
	}
};


int main()
{

    return 0;
}