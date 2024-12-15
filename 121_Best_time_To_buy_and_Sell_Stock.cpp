#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0; int max_Profit=0; int buy=prices[0]; int sell=prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i]<buy)
            {
                buy = prices[i];
                sell = buy;
            }
            else if(prices[i]>sell){
                sell = prices[i];
            }
            profit = sell - buy;
            max_Profit = profit>max_Profit?profit:max_Profit;
        }
        return max_Profit;
    }
};
int main()
{
    Solution solution;
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    cout<<solution.maxProfit(prices)<<endl;

    return 0;
}