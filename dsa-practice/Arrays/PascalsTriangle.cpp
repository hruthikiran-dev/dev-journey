// Problem: Pascal's Triangle
// Platform: LeetCode 118
// Pattern: Dynamic Programming / Simulation
// Key Insight:
// - Build the triangle row by row.
// - Initialize each row with all 1's, then compute only the middle
//   elements using the two elements directly above from the previous row.
// Time: O(n²)
// Space: O(n²)

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};