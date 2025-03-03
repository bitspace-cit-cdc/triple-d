# K-diff Pairs in an Array   


Given an array of integers `nums`, and two integers `k` and `s`, return the number of unique k-diff pairs in the array such that the sum of the pair is less than or equal to `s`.

A k-diff pair is an integer pair `(nums[i], nums[j])`, where the following are true:  

- `0 <= i, j < nums.length`  
- `i != j`  
- `|nums[i] - nums[j]| == k`  

Notice that `|val|` denotes the absolute value of `val`.  

### Example 1:  

Input: nums = `[3, 1, 4, 1, 5]`, k = 2, s = 8 
Output: 1  
Explanation: There is only one 2-diff pair in the array with sum ≤ 8: (3, 5).  

---
### Example 2:  

Input: nums = `[1, 2, 3, 4, 5]`, k = 1, s = 7  
Output: 3  
Explanation: There are three 1-diff pairs with sum ≤ 7: (1, 2), (2, 3), and (3, 4). The pair (4, 5) is excluded because its sum is greater than 7.  

---
### Example 3:  

Input: nums = `[1, 3, 1, 5, 4]`, k = 0, s = 5  
Output: 1  
Explanation: There is only one 0-diff pair in the array with sum ≤ 5: (1, 1).  

---
### Constraints:  

- `1 <= nums.length <= 10^4`  
- `-10^7 <= nums[i] <= 10^7`  
- `0 <= k <= 10^7`  
- `0 <= s <= 10^7`  
