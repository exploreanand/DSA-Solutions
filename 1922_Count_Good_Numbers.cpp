#include <iostream>
using namespace std;

// The optimal and binary exponentiation with modulo
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long pow(long long x, long long n){
        long long nn = n;
        long long res = 1;

        while(nn>0){
            if(nn%2 == 1){
                res = (res * x)%MOD;
                nn = nn - 1;
            }
            else{
                x = (x * x)%MOD;
                nn = nn/2;
            }
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (pow(5, even) * pow(4, odd))%MOD;
    }
};

int main()
{

    return 0;
}