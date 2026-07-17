// Problem: Majority Element
// Platform: LeetCode 169
// Pattern: Moore's Voting Algorithm
// Key Insight:
// - Maintain a candidate and a count.
// - Increment the count for the same element and decrement it for different elements.
// - Different elements cancel each other's votes, so the majority element survives as the final candidate.
// Time: O(n)
// Space: O(1)


#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
            else{
                if(ele==nums[i]){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        return ele;
    }
};