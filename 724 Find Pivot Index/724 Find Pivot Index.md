#  Find Pivot Index  


Given an array of integers `nums`, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. However, you should **only return the pivot index if the number at that index is greater than the index itself**.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

If no index satisfies this condition, return -1.

 ---

Example 1:

Input: nums = `[1,7,3,6,5,6]`  
Output: 3  
Explanation:  
The pivot index is 3.  
Left sum = nums`[0]` + nums`[1]` + nums`[2]` = 1 + 7 + 3 = 11  
Right sum = nums`[4]` + nums`[5]` = 5 + 6 = 11  
Since `nums[3] = 6`, which is **greater than 3**, the pivot index is returned as 3.

---
Example 2:

Input: nums = `[1,2,3]`  
Output: -1  
Explanation:  
There is no index that satisfies the condition of the number being greater than its index after the left-right sum condition.

---
Example 3:

Input: nums = `[1, 7, 3, 1, 5, 6]`  
Output: -1  
Explanation:  
There is no index where the number is greater than the index. 

--- 

Constraints:  

- 1 <= nums.length <= 104  
- -1000 <= nums`[i]` <= 1000  
