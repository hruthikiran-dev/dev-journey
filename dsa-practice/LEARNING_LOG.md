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


### Day 2 – Arrays | Matrix Manipulation + Two Pointers + Sorting

### Problem - 1 (Arrays | Matrix Manipulation)
Rotate Image (LeetCode 48)

### What I learned
- A 90° clockwise rotation can be performed in-place by first transposing the matrix and then reversing every row. Transposing swaps rows with columns, and reversing each row changes the orientation to produce the required rotation.
- for 180°, you first reverse row and then reverse col.
- for 270°, you first transpose and then reverse col.

### What confused me
- Initially, it wasn't obvious why performing a transpose followed by reversing each row results in a 90° clockwise rotation.
- I also explored the layer-by-layer four-way swap approach, but the index calculations were more difficult to understand and remember.

### What I fixed
- Swapped only the elements above the main diagonal to transpose the matrix without affecting previously swapped elements.
- Reversed each row after transposition to complete the rotation in **O(n²)** time using **O(1)** extra space.

### Problem - 2 (Arrays | Sorting + Interval Merging)
Merge Intervals (LeetCode 56)

### What I learned
- Sorting the intervals by their starting time ensures that all overlapping intervals appear consecutively.
- Instead of creating separate variables for the current interval, the last interval stored in the result can be updated directly whenever an overlap is found.

### What confused me
- Initially, I assumed I could merge intervals without sorting, but I realized overlapping intervals may not be adjacent in an unsorted array.
- I also forgot to extend the merged interval using the maximum ending point, which could incorrectly shrink the merged interval.

### What I fixed
- Sorted the intervals before processing to ensure overlaps are handled correctly.
- Used the last interval in the result vector to merge overlapping intervals by updating its ending value with the maximum end point.

### Problem - 3 (Arrays | Three Pointers)
Merge Sorted Array (LeetCode 88)

### What I learned
- Since nums1 already has enough space at the end, merging from the back prevents overwriting elements that are still needed.
- Comparing the largest remaining elements from both arrays allows the merged array to be built in-place without using extra space.

### What confused me
- Initially, I tried merging from the front using an extra array, which worked but required O(m+n) extra space.
- I also made pointer initialization mistakes and forgot that the second pointer should start at n-1, not n.

### What I fixed
- Switched to the three-pointer approach by starting from the end of both arrays and filling nums1 from the last index.
- Correctly initialized the pointers and merged the arrays in-place with O(m+n) time and O(1) extra space.

### Problem - 4 (Arrays | Floyd's Cycle Detection)
Find the Duplicate Number (LeetCode 287)

### What I learned
- An array can be viewed as a linked list by treating each value as the index of the next node.
- The duplicate number creates a cycle, allowing Floyd's Slow & Fast Pointer algorithm to detect the cycle and identify its starting point in O(n) time using O(1) extra space.

### What confused me
- Initially, it was difficult to understand how an array could be treated as a linked list and why a duplicate number forms a cycle.
- I also found the second phase of Floyd's algorithm confusing, especially why resetting one pointer to the beginning and moving both pointers one step at a time always leads to the duplicate.

### What I fixed
- Understood the array-to-linked-list mapping and how the duplicate becomes the entry point of the cycle.
- Correctly implemented both phases of Floyd's algorithm: first detecting the meeting point and then finding the cycle's entrance to return the duplicate number.


### Day 3 – Binary Search | Binary Exponentiation + Moore's Voting

### Problem - 1 (Binary Search | Matrix Search)
Search a 2D Matrix (LeetCode 74)

### What I learned
- A globally sorted matrix can be searched efficiently using binary search instead of checking every element.
- Learned two approaches: first finding the candidate row and then searching within it, and the optimal approach of treating the matrix as a virtual 1D sorted array.

### What confused me
- I was confused about how to identify the correct row after the first binary search and why `row = h` works.
- It was also difficult to understand how a 2D matrix could be treated as a 1D sorted array without actually flattening it.

### What I fixed
- Understood that `h` points to the last possible candidate row after the first binary search.
- Learned to map a virtual 1D index back to the matrix using `row = mid / cols` and `col = mid % cols`.

### Problem - 2 (Binary Search   | Binary Exponentiation)
Pow(x, n) (LeetCode 50)

### What I learned
- Binary Exponentiation reduces the number of multiplications by processing the exponent in its binary form.
- Squaring the base after every step and multiplying it with the answer only when the current exponent bit is `1` gives an `O(log n)` solution.

### What confused me
- Initially, I thought bitwise left shift (`<<`) could be used to calculate powers.
- I also found it difficult to understand why repeatedly squaring the base still produces the correct answer.

### What I fixed
- Understood that `<<` only multiplies a number by powers of two, not computes arbitrary powers.
- Learned how binary representation of the exponent determines which powers of the base contribute to the final answer.

### Problem - 3 (Arrays | Moore's Voting Algorithm)
Majority Element (LeetCode 169)

### What I learned
- Moore's Voting Algorithm finds the majority element by maintaining only a candidate and a counter.
- Different elements cancel each other's votes, so the majority element survives as the final candidate.

### What confused me
- I initially believed storing frequencies using a HashMap was necessary to solve the problem.
- It was difficult to understand how the algorithm could correctly identify the majority element without keeping track of every element's frequency.

### What I fixed
- Understood that only one candidate and a counter are needed because different elements cancel each other's votes.
- Learned why the majority element always remains after all possible cancellations, making the algorithm work in `O(n)` time and `O(1)` space.


### Day 4 –  Moore's Voting

### Problem - 1 (Arrays | Boyer-Moore Voting Algorithm)
Majority Element II (LeetCode 229)

### What I learned
- There can be at most two elements appearing more than ⌊n/3⌋ times.
- Boyer-Moore Voting Algorithm uses two candidates and two counters to find potential majority elements in O(n) time and O(1) space.
- A second pass is needed to verify the actual frequencies of the candidates.

### What confused me
- Initially, I thought the counters represented actual frequencies and that one pass was enough.
- It was confusing why both counters are decremented when a different element appears.

### What I fixed
- Understood that the counters store vote balance, not frequency.
- Fixed the candidate checking order before assigning new candidates.
- Verified the final answer using `count > ⌊n/3⌋`.