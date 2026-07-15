// Problem: Maximum Subarray
// Platform: LeetCode 53
// Pattern: Kadane's Algorithm / Dynamic Programming
// Key Insight:
// - Maintain a running sum while traversing the array.
// - If the running sum becomes negative, reset it to 0 since it cannot
//   contribute to a larger subarray. Keep updating the maximum sum found.
// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int summ=0;
        int res=nums[0];
        for(int i=0;i<nums.size();i++){
            if(summ<0){
                summ=0;
            }
            summ+=nums[i];
            res=max(res,summ);
        }
        return res;
    }
};
