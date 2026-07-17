// Problem: Search a 2D Matrix
// Platform: LeetCode 74
// Pattern: Binary Search | Matrix
// Key Insight:
// - Since the matrix is globally sorted, it can be searched efficiently using binary search.
// - Approach 1: Binary search on the first column to locate the candidate row, then binary search within that row.
// - Approach 2 (Optimal): Treat the matrix as a virtual 1D sorted array and perform a single binary search using:
//   -> row = mid / cols
//   -> col = mid % cols
// Time: O(log(m*n))
// Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int l=0,h=r-1,mid;
        while(l<=h){
            mid=(l+h)/2;
            if(matrix[mid][0]>target){
                h=mid-1;
            }
            else if(matrix[mid][0]<target){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        if(h < 0)
            return false;
        int row=h;
        l=0;
        h=c-1;
        while(l<=h){
            mid=(l+h)/2;
            if(matrix[row][mid]>target){
                h=mid-1;
            }
            else if(matrix[row][mid]<target){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int h = rows * cols - 1;

        while (l <= h) {

            int mid = l + (h - l) / 2;

            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }

        return false;
    }
};