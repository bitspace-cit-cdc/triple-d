MOD = 10**9 + 7

def countPalindromicSubsequences(s: str, allowed: str) -> int:
    allow_set = set(allowed)
    s_filtered = "".join(c for c in s if c in allow_set)
    n = len(s_filtered)
    memo = [[-1]*n for _ in range(n)]
    
    def dp(i, j):
        if i > j:
            return 0
        if memo[i][j] != -1:
            return memo[i][j]
        ans = 0
        for c in "abcdefghijklmnopqrstuvwxyz":
            left, right = i, j
            while left <= j and s_filtered[left] != c:
                left += 1
            while right >= i and s_filtered[right] != c:
                right -= 1
            if left > j:
                continue
            if left == right:
                ans = (ans + 1) % MOD
            else:
                ans = (ans + 2 + dp(left+1, right-1)) % MOD
        memo[i][j] = ans
        return ans
    
    return dp(0, n-1)

if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().split()
    t = int(input_data[0])
    idx = 1
    results = []
    for _ in range(t):
        s = input_data[idx]; idx += 1
        allowed = input_data[idx]; idx += 1
        results.append(str(countPalindromicSubsequences(s, allowed)))
    sys.stdout.write("\n".join(results))