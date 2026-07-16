// Problem: Rotate Image
// Platform: LeetCode 48
// Pattern: Matrix Manipulation (Transpose + Reverse)
// Key Insight:
// - Transpose the matrix by swapping elements across the main diagonal.
// - Reverse every row to convert the transposed matrix into a 90° clockwise rotation.
// Time: O(n²)
// Space: O(1)


#include <vector>   
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};