### Longest Geometric Subsequence  

Given an array `nums` of integers, return the length of the **longest geometric subsequence** in `nums`.  

A subsequence is called **geometric** if:  
- It has at least **two** elements.  
- The ratio between consecutive elements is **constant** (i.e., `seq[i+1] / seq[i]` remains the same for all valid `i`).  
- The ratio must be an **integer** (i.e., `seq[i+1]` is divisible by `seq[i]`).  

### Example 1:  
**Input:** `nums = [2,6,18,54]`  
**Output:** `4`  
**Explanation:** The whole array forms a geometric sequence with ratio `3`.  

### Example 2:  
**Input:** `nums = [5,10,20,25,50]`  
**Output:** `3`  
**Explanation:** The longest geometric subsequence is `[5,10,20]` with ratio `2`.  

### Example 3:  
**Input:** `nums = [3,9,12,36,108]`  
**Output:** `3`  
**Explanation:** The longest geometric subsequence is `[3,9,36]` with ratio `3`.  

### Constraints:  
- `2 <= nums.length <= 1000`  
- `1 <= nums[i] <= 500`  
- All elements in `nums` are **positive** (to avoid division issues).  
