# Problem: Check if Array Is Sorted and Rotated
# Platform: LeetCode 1752
# Pattern: Array Traversal
# Key Insight:
# - In a sorted rotated array, there can be at most ONE place
#   where nums[i] > nums[i+1]
# - That position represents the rotation pivot
# - Use modulo (%) to circularly compare last element with first
# Time: O(n)
# Space: O(1)

class Solution(object):
    def check(self, nums):

        count = 0
        n = len(nums)
        for i in range(n):

            # Circular comparison
            if nums[i] > nums[(i + 1) % n]:
                count += 1

        return count <= 1
# Taking input
nums = list(map(int, input("Enter array elements: ").split()))

# Creating object
obj = Solution()

# Calling function
result = obj.check(nums)

# Printing result
print(result)