// Problem: Majority Element II
// Platform: LeetCode 229
// Pattern: Boyer-Moore Voting Algorithm
// Key Insight:
// - There can be at most two elements that appear more than ⌊n/3⌋ times.
// - Use two candidates and two counters to maintain potential majority elements.
// - Matching elements increase their respective counters.
// - A new element replaces a candidate whose counter becomes zero.
// - If the current element matches neither candidate and both counters are non-zero,
//   decrement both counters to cancel out votes.
// - Perform a second pass to verify the actual frequencies of the two candidates.
// Time: O(n)
// Space: O(1) extra


#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0,b=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i])
                cnt1++;
            else if(b==nums[i])
                cnt2++;
            else if(cnt1==0){
                a=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                b=nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i]){
                cnt1++;
            }
            else if(b==nums[i]){
                cnt2++;
            }
        }
        int minimum=(nums.size()/3);
        if(cnt1>minimum){
            res.push_back(a);
        }
        if(cnt2>minimum){
            res.push_back(b);
        }
        return res;
    }
};