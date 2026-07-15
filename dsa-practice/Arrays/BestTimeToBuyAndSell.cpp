// Problem: Best Time to Buy and Sell Stock
// Platform: LeetCode 121
// Pattern: Array Traversal / Prefix Minimum
// Key Insight:
// - Traverse the array while keeping track of the minimum price seen so far.
// - Treat each day as a potential selling day and calculate the profit using
//   the minimum buying price encountered before it.
// Time: O(n)
// Space: O(1)


#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int minny=prices[0];
        for(int i=1;i<prices.size();i++){
            minny=min(minny,prices[i]);
            int profit=prices[i]-minny;
            res=max(res,profit);
        }
        return res;
    }
};