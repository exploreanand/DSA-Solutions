#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long total_hours(vector<int> &piles, int mid)
    {
        long long hours = 0;
        for (int pile : piles)
        {
            hours += (long long)(pile + mid - 1) / mid;
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            long long hours = total_hours(piles, mid);
            if (hours <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{

    return 0;
}