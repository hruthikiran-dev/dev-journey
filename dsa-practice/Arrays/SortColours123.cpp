// Problem: Sort Colors
// Platform: LeetCode 75
// Pattern: Dutch National Flag Algorithm / Three Pointers
// Key Insight:
// - Maintain three pointers (low, mid, high) to partition the array
//   into 0s, 1s, and 2s in a single traversal.
// - Swap 0s to the front, 2s to the back, and leave 1s in the middle.
// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==1){
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            }
            else{
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
        }
    }
};