# Average Size of Closed Island

You are given a 2D grid consisting of 0s (land) and 1s (water). An island is a group of adjacent 1s (either horizontally or vertically). You need to determine the **average size** of all islands in the grid.

The area of an island is the number of connected cells with a value of 1. For each island, its size is calculated by counting the connected 1s in that island.

Return the average size of the islands in the grid, or 0 if no island exists.

---
### Example 1:

**Input**:
```
grid = [[1,1,1,1,1,1,1,0],
		[1,0,0,0,1,1,1,0],
		[1,0,1,0,1,1,1,0],
		[1,0,0,0,0,1,0,1],
		[1,1,1,1,1,1,1,0]]
```

**Output**:
5.0


**Explanation**: The sizes of the islands are `[9, 1]`, and their average is `(9 + 1) / 2 = 5.0`.

---
### Example 2:

**Input**:

```
grid = [[1,0,1,0],
        [0,1,1,0],
        [1,1,0,1],
        [0,0,1,1]]
```

**Output:**

1.0


**Explanation**: The sizes of the islands are `[1]`, and their average is `1 / 1 = 1.0`.

---
### Example 3:

**Input**:


```
grid = [[0,0,0],
        [0,0,0],
        [0,0,0]]`
```



**Output**:

0.0


**Explanation**: There are no islands.

---
### Constraints:

- `1 <= grid.length, grid[0].length <= 100`
- `0 <= grid[i][j] <= 1`