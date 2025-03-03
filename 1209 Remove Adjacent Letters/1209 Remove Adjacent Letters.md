# Remove Adjacent Letters

You are given a string `s`, an integer `k`, and an integer threshold `t`. A **k-removal** is defined as follows:

1. **Score Calculation:**  
    For any group of `k` consecutive characters in `s` (denoted as `s[i...i+k-1]`), calculate the score by summing the absolute differences between every two adjacent characters.

The score is calculated as:
`score = |ord(s[i+1]) - ord(s[i])| + |ord(s[i+2]) - ord(s[i+1])| + ... + |ord(s[i+k-1]) - ord(s[i+k-2])|`

Here, `ord(x)` returns the ASCII value of the character `x`.

2. **Removal Condition:**  
    If the score is **strictly greater** than `t`, remove that group of `k` consecutive characters from `s`.
    
3. **Process:**  
    Repeat the above steps as long as there exists a group of `k` consecutive characters that satisfies the removal condition. After each removal, the string "collapses" (the remaining parts come together), which may form new groups of `k` consecutive characters that can be removed.

Return the final string after all possible removals have been performed.


### Example 1

**Input:**  
`s = "abcdef"`, `k = 3`, `t = 2`

**Output:**  
`"abcdef"`

**Explanation:**  
For the group `"abc"`, the score is calculated as:  
`|ord('b') - ord('a')| + |ord('c') - ord('b')| = 1 + 1 = 2`  
Since `2` is not strictly greater than `t = 2`, no removal occurs.

### Example 2

**Input:**  
`s = "acfg"`, `k = 2`, `t = 1`

**Output:**  
`"fg"`

**Explanation:**  
For the group `"ac"`, the score is:  
`|ord('c') - ord('a')| = 2`  
Since `2` is strictly greater than `t = 1`, `"ac"` is removed, leaving `"fg"`.

### Example 3

**Input:**  
`s = "aceg"`, `k = 2`, `t = 2`

**Output:**  
`"aceg"`

**Explanation:**  
No group of `2` consecutive characters in `"aceg"` has a score strictly greater than `t = 2`, so the string remains unchanged.

## Constraints

- `1 ≤ s.length ≤ 10^5`
- `2 ≤ k ≤ 10^4`
- `0 ≤ t ≤ 25`
- `s` consists of lowercase English letters only.