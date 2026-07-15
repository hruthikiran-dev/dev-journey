## Day 1 – Arrays | Contribution Technique

### Problem
Sum of Sum of All Subarrays
### What I learned
- Each element contributes independently.
- arr[i] appears in (i + 1) * (n - i) subarrays.
### What confused me
- Why the multiplication formula works.
- Why my code failed for large inputs.
### What I fixed
- Understood start/end index combinations.
- Changed int to long long to avoid overflow.


## Day 2 – Heaps 

### What I learned
- The K-th smallest element is the largest among the K smallest elements.
- Maintaining a max heap of size K ensures that we always store the current K smallest elements.
- The top of the max heap represents the worst (largest) element among these K smallest elements.

### What confused me
- How removing and replacing elements in the heap guarantees that the final heap top is the correct K-th smallest element.
- Why elements larger than the heap top can be safely ignored.

### What I fixed
- Understood that any element greater than the heap top cannot be among the K smallest elements.
- Replaced the heap top whenever a smaller element was found, ensuring the heap always contains the K smallest elements.
- Realized that after processing all elements, the heap top must be the K-th smallest element.


## Day 3 – Check if Array Is Sorted and Rotated

### What I learned
- A sorted and rotated array can have at most one “drop” point where:
  nums[i] > nums[i+1]
- That drop point represents the rotation pivot.
- Circular comparison using modulo (%) helps compare the last element with the first element.
- If more than one drop exists, the array cannot be sorted and rotated.

### What confused me
- Initially thought I needed to reconstruct the original array using reversals.
- Got confused between increasing/decreasing trend changes and actual rotation validity.
- Handling edge cases like:
  [2,1]
  [1,1,1,0,1]
  was tricky.

### What I fixed
- Understood that counting ordering violations is enough.
- Used: nums[(i + 1) % n] to make the array behave circularly.
- Realized that: count <= 1 is the complete condition for a valid sorted rotated array.


## Day 1 – Arrays | Matrix Traversal + Hashing

### Problem - 1
Set Matrix Zeroes (LeetCode 73)

### What I learned
- A separate data structure can be used to remember which rows and columns need modification.
- Using hash sets for row and column indices avoids changing the matrix while traversing it.

### What confused me
- Initially, I thought of marking affected cells with `-1`, but realized the matrix itself can contain `-1`.
- Then I considered creating a separate 2D matrix to mark changes and copying it back, but found a simpler approach using row and column sets.

### What I fixed
- Stopped relying on a special marker value that could already exist in the matrix.
- Used two `unordered_set`s to store row and column indices, then updated the matrix in a second traversal.

### Problem - 2 (Arrays | Dynamic Programming / Simulation)
Pascal's Triangle (LeetCode 118)

### What I learned
- Each row can be built directly from the previous row without creating an unnecessary `n × n` matrix.
- The first and last elements of every row are always `1`; only the middle elements need to be calculated.

### What confused me
- Initially, I created an `n × n` matrix, filled it completely, and then extracted only the required elements into the final answer.
- Later, I realized that each row has only `i + 1` elements, so building rows directly is much cleaner and more space-efficient.

### What I fixed
- Replaced the extra `n × n` matrix with a temporary vector representing the current row.
- Initialized each row with `1`s and filled only the middle elements using the previous row before adding it to the result.

### Problem - 3 (Arrays | Greedy + Two Pointers)
Next Permutation (LeetCode 31)

### What I learned
- The next permutation can be obtained by modifying only the suffix of the array.
- After finding the breakpoint, swapping with the rightmost greater element and reversing the suffix gives the immediate next lexicographical order.

### What confused me
- I also forgot to handle the case where no breakpoint exists, meaning the array is already the largest permutation.

### What I fixed
- Handled the `bp == -1` case by reversing the entire array, then used `reverse()` on the suffix after swapping to generate the next permutation.

### Problem - 4 (Arrays | Kadane's Algorithm)
Maximum Subarray (LeetCode 53)

### What I learned
- Kadane's Algorithm finds the maximum subarray sum in a single traversal by maintaining a running sum.
- A negative running sum is never useful for future subarrays, so it can be safely discarded.

### What confused me
- Initially, I thought of solving it using brute force by generating every possible subarray.
- Then I optimized the brute force approach using a running sum, explored the Divide & Conquer solution, and finally understood why Kadane's Algorithm is the optimal approach.

### What I fixed
- Shifted from checking all possible subarrays to making a greedy decision at each index.
- Learned to reset the running sum whenever it becomes negative while continuously tracking the maximum sum obtained so far.

### Problem - 5 (Arrays | Dutch National Flag Algorithm)
Sort Colors (LeetCode 75)

### What I learned
- The array can be sorted in a single traversal using three pointers (`low`, `mid`, and `high`) without using any extra space.
- The Dutch National Flag Algorithm partitions the array into three regions for `0`s, `1`s, and `2`s while traversing only once.

### What confused me
- Initially, I thought of simply using the built-in `sort()` function, but it doesn't satisfy the intended linear-time, constant-space solution.
- Then I implemented the frequency count approach, which works but requires two traversals.
- Finally, I learned the Dutch National Flag Algorithm, which is the optimal one-pass solution.

### What I fixed
- Replaced the sorting-based solution with a linear-time approach.
- Improved the frequency count method by using the three-pointer technique to sort the array in-place with O(1) extra space.

### Problem - 6 (Arrays | Prefix Minimum)
Best Time to Buy and Sell Stock (LeetCode 121)

### What I learned
- Instead of checking every possible buying day, maintain the minimum stock price seen so far while traversing the array.
- For each day, treat it as the selling day and calculate the maximum possible profit using the minimum buying price.

### What confused me
- Initially, I thought of using two loops: considering every day as the selling day and checking all previous days as possible buying days to compute the maximum profit.
- Later, I realized I only need to remember the smallest price encountered so far instead of repeatedly scanning the left side.

### What I fixed
- Replaced the nested-loop approach with a single traversal by maintaining a prefix minimum.
- Computed the profit for each selling day in O(1) time and updated the maximum profit obtained so far.