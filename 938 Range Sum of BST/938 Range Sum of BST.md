# Range Sum of BST 

Given the root node of a binary search tree and two integers `low` and `high`, return the sum of values of all nodes with a value in the inclusive range [low, high], **only for nodes that are present at a height less than `k`**. 

A node's height is defined as the number of edges from the node to the root.

### Example:

#### Input:
```plaintext
root = [10,5,15,3,7,null,18]
low = 7
high = 15
k = 2
```

#### Output:
`25`

#### Explanation:
- Nodes 10, and 15 are within the range [7, 15] and height less than 2.
- The sum of their values is `10 + 15 = 32`.
- Only nodes that are present at a height less than `k` are included in the sum.
- In this example, the nodes at height 0 and 1 are included, while nodes at height 2 or greater are excluded.

### Constraints:
- 1 <= Node.val <= 10^5
- 1 <= low <= high <= 10^5
- The height constraint ensures only nodes with a height strictly less than `k` are considered for the sum.
