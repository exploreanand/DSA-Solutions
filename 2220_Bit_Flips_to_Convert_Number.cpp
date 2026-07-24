#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans = start ^ goal;
        int count = 0;
        while(ans){
            ans &= (ans - 1);
            count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}