#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int count = 0;
    void merge(int arr[], int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        int x = 0;
        int size = high - low + 1;
        int *temp_arr = new int[size];
        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                temp_arr[x] = arr[i];
                x++;
                i++;
            }
            else
            {
                temp_arr[x] = arr[j];
                x++;
                j++;
            }
        }
        while (i <= mid)
        {
            temp_arr[x] = arr[i];
            x++;
            i++;
        }
        while (j <= high)
        {
            temp_arr[x] = arr[j];
            x++;
            j++;
        }
        for (int k = low; k <= high; k++)
        {
            arr[k] = temp_arr[k - low];
        }
        delete[] temp_arr;
    }

    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            sort(arr, low, mid);
            sort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    int reversePairs(vector<int> &nums)
    {

        return 0;
    }
};

int main()
{

    return 0;
}