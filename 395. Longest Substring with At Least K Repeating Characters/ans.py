from collections import Counter

def longestSubstring(s: str, k: int) -> str:
    if len(s) == 0 or k > len(s):
        return ""
    c = Counter(s)
    sub1, sub2 = "", ""
    for i, letter in enumerate(s):
        if c[letter] < k:
            sub1 = longestSubstring(s[:i], k)
            sub2 = longestSubstring(s[i+1:], k)
            break
    else:
        return s
    return max(sub1,sub2)

s = input()
k = int(input())
print(longestSubstring(s, k))