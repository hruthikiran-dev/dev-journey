// Problem: Pow(x, n)
// Platform: LeetCode 50
// Pattern: Binary Exponentiation
// Key Insight:
// - Represent the exponent in binary and process it bit by bit.
// - If the current bit is 1, multiply the answer by the current base.
// - Square the base and halve the exponent after each step to reduce computations.
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;      // Handle INT_MIN
        double ans = 1.0;

        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        while (exp > 0) {
            if (exp & 1) {      // If current bit is 1 (odd)
                ans *= x;
            }

            x *= x;             // Square the base
            exp >>= 1;          // Divide exponent by 2
        }

        return ans;
    }
};