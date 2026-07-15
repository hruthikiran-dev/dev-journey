// Problem: Next Permutation
// Platform: LeetCode 31
// Pattern: Greedy + Two Pointers
// Key Insight:
// - Find the first element (breakpoint) from the right that is smaller
//   than its next element.
// - Swap it with the next greater element on its right, then reverse
//   the suffix to obtain the next lexicographically greater permutation.
// Time: O(n)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                bp=i-1;
                break;
            }
        }
        if(bp==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
            for(int i=n-1;i>bp;i--){
                if(nums[i]>nums[bp]){
                    swap(nums[i],nums[bp]);
                    break;
                }
            }
            reverse(nums.begin() + bp + 1, nums.end());
        
    }
};
