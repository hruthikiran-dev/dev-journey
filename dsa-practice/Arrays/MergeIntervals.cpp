// Problem: Merge Intervals
// Platform: LeetCode 56
// Pattern: Sorting + Interval Merging
// Key Insight:
// - Sort the intervals by their starting time.
// - Traverse the sorted intervals and merge overlapping intervals by
//   updating the end of the last merged interval; otherwise, add the
//   current interval as a new interval.
// Time: O(n log n)
// Space: O(n)


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res[res.size()-1][1]){
                res[res.size()-1][1]=max(intervals[i][1],res[res.size()-1][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};