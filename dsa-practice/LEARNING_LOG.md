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




