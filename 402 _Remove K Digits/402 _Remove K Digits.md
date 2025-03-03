### **Remove K Digits 

You are given a string `num` representing a non-negative integer, and an integer `k`. Your task is to remove `k` digits from `num` to form two distinct numbers: one that maximizes the value and one that minimizes the value, then return the **absolute difference** between the two numbers.

- You must remove exactly `k` digits.
- The result cannot have leading zeros, except when the result is "0".
- If the number after removal becomes empty, consider it as 0.

### **Input:**
- A string `num` representing a non-negative integer (`1 <= num.length <= 10^5`).
- An integer `k` (`1 <= k <= num.length`).

### **Output:**
- Return the absolute difference between the maximum number and the minimum number after removing exactly `k` digits.

### **Example 1:**
**Input:**  
`num = "1432219", k = 3`  
**Output:**  
`3110`  
**Explanation:**  
- The smallest possible number after removing 3 digits is `"1219"`.
- The largest possible number after removing 3 digits is `"4329"`.
- The difference is `4329 - 1219 = 900`.

---

### **Example 2:**
**Input:**  
`num = "10200", k = 1`  
**Output:**  
`1000`  
**Explanation:**  
- The smallest possible number after removing 1 digit is `"200"`.
- The largest possible number after removing 1 digit is `"1200"`.
- The difference is `1200 - 200 = 1000`.

---

### **Example 3:**
**Input:**  
`num = "10", k = 2`  
**Output:**  
`0`  
**Explanation:**  
- After removing all digits, the number becomes `0`.
- The difference is `0 - 0 = 0`.

---

### **Constraints:**
1. `1 <= k <= num.length <= 10^5`
2. `num` consists of only digits (`'0'` to `'9'`).
3. `num` does not have any leading zeros, except when `num` is `"0"`.
