#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int f = 0;
    int t = 0;
public:
    
    bool lemonadeChange(vector<int>& bills) {
        
        for(int bill : bills){
            if(bill == 5){
                f++;
            }
            else if(bill == 10){
                if(f == 0){return false;}
                else if(f > 0){
                    f--;
                    t++;
                }
            }
            else{
                if(t > 0 && f > 0){
                    t--;
                    f--;
                }
                else if(f >= 3){
                    f -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}