#  Convert Binary Number in a Linked List to Integer  


Given `head`, which is a reference node to a singly-linked list, the value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

**However**, before converting the binary number to a decimal, **if the total length of the list is even, invert the bits (0 becomes 1, and 1 becomes 0)**. After the inversion (if applicable), then return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

---
**Example 1:**

Input: head = `[1,0,1]`  
Output: 5  
Explanation:  
Since the length of the list is 3 (odd), the list is not inverted.  
The binary number represented by the list is 101, which equals 5 in decimal.

---
**Example 2:**

Input: head = `[1,0,1,0]`  
Output: 5  
Explanation:  
Since the length of the list is 4 (even), invert the bits before converting.  
Inverted list becomes `[0,1,0,1]`, which is 0101 in binary, and it equals 5 in decimal.

---
**Example 3:**

Input: head = `[0]`  
Output: 0  
Explanation:  
The length of the list is 1 (odd), and the list does not need to be inverted. The number is 0 in binary and hence 0 in decimal.

 ---

Constraints:

- The Linked List is not empty.
- Number of nodes will not exceed 30.
- Each node's value is either 0 or 1.
