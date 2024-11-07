#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n==0){
            cout<<n<<" ";
            return 0;}
        else if (n==1){
            cout<<n<<" ";
            return 1;}
        int ans = fib(n-2) + fib(n-1);
        return ans;
    }
};
int main()
{
    Solution obj;
    obj.fib(9);
    return 0;
}