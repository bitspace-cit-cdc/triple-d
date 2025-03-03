##  Sum of All Left Nodes


Given the root of a binary tree, return the sum of all left nodes.

A left node is defined as a node that is the left child of its parent. 

---
### Example 1:

**Input**:  
`root = [3,9,20,null,null,15,7]`

**Output**:  
`29`

**Explanation**:  
- The left nodes in the binary tree are nodes with values `9` and `15`.  
- Their sum is `9 + 15 = 24`.

---
### Example 2:

**Input**:  
`root = [1]`

**Output**:  
`0`

**Explanation**:  
- There are no left nodes since the tree only consists of the root node.

---
### Constraints:

- The number of nodes in the tree is in the range `[1, 1000].`
- -1000 <= Node.val <= 1000
