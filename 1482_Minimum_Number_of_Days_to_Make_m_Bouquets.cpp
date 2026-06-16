#include <iostream>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int consecutive = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutive++;

                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;

                    if (bouquets >= m)
                        return true;
                }
            } else {
                consecutive = 0;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, mid, m, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main()
{

    return 0;
}