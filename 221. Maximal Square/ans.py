def maximalSquare(matrix, dp):
    m, n = len(matrix), len(matrix[0])
    
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == '1':
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

m, n, q = map(int, input().split())

matrix = [list(input()) for _ in range(m)]

dp = [[0] * n for _ in range(m)]

maximalSquare(matrix, dp)

queries = [tuple(map(int, input().split())) for _ in range(q)]

for i, j in queries:
    print(dp[i][j], end=" ")
print()