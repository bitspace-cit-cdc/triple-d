#  Subtract Strings  
 

Given two non-negative integers, num1 and num2 represented as strings, return the result of subtracting the smaller number from the larger one as a string.You cannot use any built-in library for handling large integers (such as BigInteger).

Additionally, you must return the result as a string. If num1 equals num2, return "0".

**Note**: Always subtract the smaller number from the larger one to avoid negative results.

 ---
Example 1:

Input: num1 = "11", num2 = "123"  
Output: "112"  
Explanation: The larger number is 123, and subtracting 11 from it gives 112. The result is "112".  

---
Example 2:

Input: num1 = "456", num2 = "77"  
Output: "379"  
Explanation: The larger number is 456, and subtracting 77 from it gives 379. The result is "379".  

---
Example 3:

Input: num1 = "10", num2 = "10"  
Output: "0"  
Explanation: Since both numbers are equal, the result is "0".  

 ---
Constraints:  

- 1 <= num1.length, num2.length <= 10^4  
- num1 and num2 consist of only digits.  
- num1 and num2 don't have any leading zeros except for the zero itself.  
