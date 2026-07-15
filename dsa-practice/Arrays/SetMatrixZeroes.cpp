// Problem: Set Matrix Zeroes
// Platform: LeetCode 73
// Pattern: Matrix Traversal + Hashing
// Key Insight:
// - Traverse the matrix and store the indices of all rows and columns
//   containing a 0 using two hash sets.
// - Traverse the matrix again and set matrix[i][j] = 0 if its row
//   or column exists in the corresponding hash set.
// Time: O(m × n)
// Space: O(m + n)

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int r=arr.size();
        int c=arr[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rows.count(i) || cols.count(j)){
                    arr[i][j]=0;
                }
            }
        }
    }
};