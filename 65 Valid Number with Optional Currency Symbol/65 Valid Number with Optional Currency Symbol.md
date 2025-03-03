# Valid Number with Optional Currency Symbol


Given a string s, return whether s is a valid number, with the condition that it may also include an optional currency symbol like `$` or `€` before the number.

For example, all the following are valid numbers:

- "$2", "€0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789".
  
While the following are not valid numbers:

- "$abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "$2e10", "+3€", "$0.5.6".

Formally, a valid number is defined as:

1. A number which may include a currency symbol `$` or `€` at the beginning, followed by either an integer or a decimal number with an optional exponent.
2. An integer number is defined as an optional sign `+` or `-`, followed by digits.
3. A decimal number is defined as:
    - Digits followed by a dot (`.`).
    - Digits followed by a dot (`.`) and more digits.
    - A dot (`.`) followed by digits.
4. An exponent is an optional "e" or "E", followed by an integer number.

---
### Example 1:

Input: s = "$0"  
Output: true  

---
### Example 2:

Input: s = "e"  
Output: false  

---
### Example 3:

Input: s = "."  
Output: false  

---
### Example 4:

Input: s = "€3.14"  
Output: true  

---
### Example 5:

Input: s = "$1e10"  
Output: true  

---
### Constraints:

- 1 <= s.length <= 20
- s consists only of English letters (both uppercase and lowercase), digits (0-9), plus `+`, minus `-`, dot `.`, and optional currency symbols `$` or `€`.