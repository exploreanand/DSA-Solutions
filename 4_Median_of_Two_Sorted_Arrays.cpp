#include <iostream>
#include <vector>
using namespace std;

// Not Optimal
// class Solution {
// public:
//     vector<int> merge(vector<int> nums1, vector<int> nums2){
//         vector<int> ans;
//         int n = nums1.size();
//         int m = nums2.size();

//         int i = 0;
//         int j = 0;

//         while(i < n && j < m){
//             if(nums1[i]<=nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while (i < n)
//         {
//             ans.push_back(nums1[i]);
//             i++;
//         }
//         while (j < m)
//         {
//             ans.push_back(nums2[j]);
//             j++;
//         }
//         return ans;
//     }

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> answer = merge(nums1, nums2);

//         int n = answer.size();
//         int mid = n/2;
//         if(n % 2 == 0){
//             double x = (answer[mid - 1] + answer[mid])/2.0;
//             return x;
//         }
//         else{
//             return answer[mid];
//         }
//     }
// };

// Optimal Code
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        if (nums1_size > nums2_size)
            return findMedianSortedArrays(nums2, nums1);
        int total_size = nums1_size + nums2_size;
        int left_len = (nums1_size + nums2_size + 1) / 2;

        int low = 0;
        int high = nums1_size;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int cut1 = mid;
            int cut2 = left_len - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int r1 = cut1 == nums1_size ? INT_MAX : nums1[cut1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r2 = cut2 == nums2_size ? INT_MAX : nums2[cut2];

            if ((l1 <= r2) && (l2 <= r1))
            {

                if (total_size % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    double median = max(l1, l2);
                    return median;
                }
            }
            else
            {
                if (l1 > r2)
                {
                    high = cut1 - 1;
                }
                else if (l2 > r1)
                {
                    low = cut1 + 1;
                }
            }
        }
        return 0.0;
    }
};

int main()
{
    
    return 0;
}