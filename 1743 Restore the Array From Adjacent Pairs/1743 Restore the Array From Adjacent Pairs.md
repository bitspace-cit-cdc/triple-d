#  Restore the Array From Adjacent Pairs


There is an integer array `nums` that consists of `n` unique elements, but you have forgotten it. However, you do remember some pairs of adjacent elements in `nums`. These pairs may not guarantee a valid reconstruction.

You are given a 2D integer array `adjacentPairs` of size `n-1`, where each `adjacentPairs[i]` = `[ui, vi]` indicates that the elements `ui` and `vi` are adjacent in `nums`.

Some of the adjacent pairs may be invalid or missing, In such cases return ``[-1]`` otherwise return the original array `nums` if it's possible to construct it, 

---
Example 1:

Input: adjacentPairs = `[[2,1]`,`[3,4]`,`[3,2]]`
Output: `[1,2,3,4]` 
Explanation: You must find which pairs correctly connect to produce a sorted array.

---
Example 2:

Input: adjacentPairs = `[[4,-2]`,`[1,4]`,`[-3,1]`, `[7, 2]]`
Output: `[-1]` 
Explanation: No valid reconstruction possible.

---
Example 3:

Input: adjacentPairs = `[[100000,-100000]]`
Output: `[100000,-100000]`

---
Constraints:
- nums.length == n
- adjacentPairs.length == n - 1
- adjacentPairs`[i]`.length == 2
- 2 <= n <= 10^5
- -10^5 <= nums`[i]`, ui, vi <= 10^5
- There may be missing or invalid pairs in adjacentPairs.
