##  Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the maximum absolute difference between the values of a node and any of its immediate descendants in the tree.

---
### Example 1:

**Input**:  
`root = [4,2,6,1,3]`

**Output**:  
`2`

**Explanation**:  
- The maximum absolute difference between a node and its immediate descendant in this tree is between node values `4` and `2`, which is `4 - 2 = 2`.

---
### Example 2:

**Input**:  
`root = [1,0,48,null,null,12,49]`

**Output**:  
`47`

**Explanation**:  
- The maximum absolute difference between a node and its immediate descendant in this tree is between node values `48` and `1`, which is `48 - 1 = 47`.

---
### Constraints:

- The number of nodes in the tree is in the range `[2, 10^4]`.
- `0 <= Node.val <= 10^5`
