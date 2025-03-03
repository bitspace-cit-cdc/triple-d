def maxLength(arr, k):
    cand = []
    for s in arr:
        mask = 0
        valid = True
        vowels = 0
        for c in s:
            bit = ord(c) - ord('a')
            if mask & (1 << bit):
                valid = False
                break
            mask |= (1 << bit)
            if c in "aeiou":
                vowels += 1
        if valid:
            cand.append((mask, vowels, len(s)))
    ans = 0
    def dfs(idx, mask, vowelCount, length):
        nonlocal ans
        if vowelCount >= k:
            ans = max(ans, length)
        for i in range(idx, len(cand)):
            cMask, cVowel, cLen = cand[i]
            if mask & cMask:
                continue
            dfs(i+1, mask | cMask, vowelCount + cVowel, length + cLen)
    dfs(0, 0, 0, 0)
    return ans

if __name__ == '__main__':
    import sys
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        arr = sys.stdin.readline().split()
        k = int(sys.stdin.readline())
        print(maxLength(arr, k))