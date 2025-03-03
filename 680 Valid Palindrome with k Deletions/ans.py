
s = input().strip()
k = int(input())
n = len(s)
dp = [[0]*n for _ in range(n)]
for i in range(n-1, -1, -1):
    dp[i][i] = 1
    for j in range(i+1, n):
        if s[i] == s[j]:
            dp[i][j] = (dp[i+1][j-1] if i+1 <= j-1 else 0) + 2
        else:
            dp[i][j] = max(dp[i+1][j], dp[i][j-1])
lps = dp[0][n-1]
print("true" if (n - lps) <= k else "false")
