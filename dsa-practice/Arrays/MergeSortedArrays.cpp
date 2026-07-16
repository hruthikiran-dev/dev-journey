// Problem: Merge Sorted Array
// Platform: LeetCode 88
// Pattern: Three Pointers (In-place Merge)
// Key Insight:
// - Start from the end of both arrays and place the larger element at
//   the last available position in nums1.
// - Filling from the back avoids overwriting the valid elements already
//   present in nums1 and achieves an in-place merge.
// Time: O(m + n)
// Space: O(1)


#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,p3=m+n-1;
        while(p1>=0 && p2>=0){
            if(nums1[p1]<nums2[p2]){
                nums1[p3--]=nums2[p2--];
            }
            else if(nums1[p1]>nums2[p2]){
                nums1[p3--]=nums1[p1--];
            }
            else{
                nums1[p3--]=nums2[p2--];
                nums1[p3--]=nums1[p1--];
            }
        }
        while(p1>=0){
            nums1[p3--]=nums1[p1--];
        }
        while(p2>=0){
            nums1[p3--]=nums2[p2--];
        }
    }
};