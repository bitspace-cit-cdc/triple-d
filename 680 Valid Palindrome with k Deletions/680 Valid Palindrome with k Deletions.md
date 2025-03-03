# Valid Palindrome with k Deletions

**Easy**  

Given a string `s` and an integer `k`, return `true` if the string can be a palindrome after deleting at most `k` characters from it. Otherwise, return `false`.  

---

## Example 1:
**Input**:  
`s = "aba", k = 1`  
**Output**:  
`true`  

---
## Example 2:
**Input**:  
`s = "abcdba", k = 2`  
**Output**:  
`true`  
**Explanation**:  
You could delete the character `'c'` and `'d'` -> `'abba'` which is a palindrome.  

---

## Example 3:
**Input**:  
`s = "abc", k = 1`  
**Output**:  
`false`  

---

## Constraints:
- `1 <= s.length <= 1000`  
- `0 <= k <= s.length`  
- `s` consists of lowercase English letters.  

