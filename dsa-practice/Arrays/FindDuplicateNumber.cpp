// Problem: Find the Duplicate Number
// Platform: LeetCode 287
// Pattern: Floyd's Cycle Detection (Slow & Fast Pointers)
// Key Insight:
// - Treat each array value as the next index, forming a linked list.
// - Use Floyd's cycle detection algorithm to find the meeting point,
//   then locate the entrance of the cycle, which is the duplicate number.
// Time: O(n)
// Space: O(1)


#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0],f=nums[0];
        do{
            s=nums[s];
            f=nums[nums[f]];
        }while(s!=f);
        s=nums[0];
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }    
        return s;
    }
};