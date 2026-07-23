#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        if(dividend == divisor){
            return 1;
        }

        bool sign = 1;
        
        if((dividend <= 0 && divisor > 0) || 
           (dividend >= 0 && divisor < 0)){
            sign = 0;
        }

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;
        while(n >= d){
            int count = 0;

            while(n >= (d << (count + 1))){
                count++;
            }
            quotient += (1LL<<count);
            n -= (d << count);
        }

        return sign ? quotient : -quotient;

    }
};

int main()
{

    return 0;
}