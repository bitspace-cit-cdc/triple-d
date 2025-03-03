#  Maximum Product of Three Numbers 


Given an integer array `nums`, find three numbers whose product is maximum **and the absolute difference between the two largest numbers in the chosen triplet is less than or equal to `k`**. It is guaranteed that at least one such triplet exists. Return the maximum product of the triplet that satisfies this condition.

The three numbers must be chosen such that the difference between the largest and second-largest numbers does not exceed `k`.

---
### Example 1:

Input: `nums = [1, 2, 3], k = 2`  
Output: `6`  
Explanation: The product `1 * 2 * 3 = 6`, and the difference between the largest (`3`) and the second largest (`2`) is `1`, which is less than or equal to `k`. Thus, the maximum product is `6`.

---
### Example 2:

Input: `nums = [1, 2, 3, 5], k = 1`  
Output: `6`  
Explanation: The product `1 * 2 * 3 = 6` is valid since the difference between the largest (`3`) and the second largest (`2`) is `1`, which satisfies the condition.

---
### Example 3:

Input: `nums = [1, 5, 3], k = 2`  
Output: `15`  
Explanation: The product `1 * 5 * 3 = 15` and the absolute difference between the largest (`5`) and the second largest (`3`) is `2`, which satisfies the condition.

---
### Constraints:

- `3 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- `0 <= k <= 1000`
- **There will always be at least one valid triplet satisfying the condition.**
