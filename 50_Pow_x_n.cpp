#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double res = 1;
        if(nn < 0){ nn = -1 * nn;}
        for(int i = 0; i < nn; i++){
            res = res*x;
        }
        if(n<0){return (double)1/(double)(res);}
        return res;
    }
};

// Optimal Solution - the standard binary exponentiation
class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double res = 1;
        if(nn < 0){nn = -1 * nn;}
        while(nn > 0){
            if(nn%2 == 1){
                res = res * x;
                nn = nn - 1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n<0){return (double)1/(double)(res);}
        return res;
    }
};

int main()
{

    return 0;
}