## Day 3 – Arrays | Contribution Technique

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