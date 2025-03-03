# Convert Sorted Array to Binary Search Tree 

Given an integer array `nums` where the elements are sorted in ascending order, convert it to a **height-balanced** inverted binary search tree where the left child node is always greater than the parent, and the right child node is always smaller than the parent. 

---

### Example 1:
**Input:**  
`nums = [-10,-3,0,5,9]`

**Output:**  
`[0,5,-10,9,null,-3]`

### Example 2:
**Input:**  
`nums = [1,3]`

**Output:**  
`[1,3]`

---

### Constraints:
- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in a strictly increasing order.

---
