# Most Stones Removed with Same Row or Column

You are given a 2D plane with `n` stones, where each stone is at a unique integer coordinate, and no two stones are at the same point. A stone can be removed if:

1. It shares the same **row** with another stone.
2. It shares the same **column** with another stone.
3. It shares either the **primary diagonal** (`xi - yi = xj - yj`) or **secondary diagonal** (`xi + yi = xj + yj`) with another stone that is not removed yet.

Given an array `stones` where each element `stones[i]` = `[x_i, y_i]` represents a stone’s position on the plane, return the largest possible number of stones that can be removed.

### Example 1:

**Input:**

stones = `[[0,0]`, `[0,1]`, `[1,0]`, `[1,2]`, `[2,1]`, `[2,2]]`

**Output:**

5

**Explanation:**
- We can remove the stones by sharing rows, columns, or diagonals:
  - Remove `[2, 2]` because it shares the same row as `[2, 1]`.
  - Remove `[2, 1]` because it shares the same column as `[0, 1]`.
  - Remove `[1, 2]` because it shares the same row as `[1, 0]`.
  - Remove `[1, 0]` because it shares the same column as `[0, 0]`.
  - Remove `[0, 1]` because it shares the same row as `[0, 0]`.
  - Hence, 5 stones can be removed. Stone `[0, 0]` cannot be removed since it shares no row/column/diagonal with remaining stones.

### Example 2:

**Input:**

stones = `[[0,0]`, `[0,2]`, `[1,1]`, `[2,0]`, `[2,2]]`

**Output:**

4

**Explanation:**
- Remove stones by sharing rows, columns, or diagonals:
  - Remove `[2, 2]` because it shares the same row as `[2, 0]`.
  - Remove `[2, 0]` because it shares the same column as `[0, 0]`.
  - Remove `[0, 2]` because it shares the same row as `[0, 0]`.
  - Remove `[1, 1]` because it shares the same primary diagonal as `[0, 0]`.
  - Hence, we can remove 4 stones.

### Example 3:

**Input:**

stones = `[[0,0]]`

**Output:**

0

**Explanation:**
- There's only one stone, so it cannot be removed.

### Constraints:

- 1 <= `stones.length` <= 1000
- 0 <= `xi`, `yi` <= 10^4
- No two stones are at the same coordinate point.
