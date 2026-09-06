#include <iostream>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int i = 0;
        int j = 0;
        int ans = 0;
        vector<pair<int, int>> tree(2, {-1, 0});

        while(j < n){

            if(fruits[j] == tree[0].first){
                tree[0].second++;
                j++;
            }
            else if(fruits[j] == tree[1].first){
                tree[1].second++;
                j++;
            }
            else if(tree[0].first == -1){
                tree[0].first = fruits[j];
                tree[0].second++;
                j++;
            }
            else if(tree[1].first == -1){
                tree[1].first = fruits[j];
                tree[1].second++;
                j++;
            }
            else{
                if(fruits[i]==tree[0].first){
                    tree[0].second--;
                    if(tree[0].second == 0){
                        tree[0].first = -1;
                    }
                }
                else{
                    tree[1].second--;
                    if(tree[1].second == 0){
                        tree[1].first = -1;
                    }
                }
                i++;
            }

            ans = max(ans, j - i);
        }
        return ans;
    }
};

int main()
{

    return 0;
}