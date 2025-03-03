
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
hasLand = False
hasWater = False
lands = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 1:
            hasLand = True
            lands.append((i, j))
        else:
            hasWater = True
if not hasLand or not hasWater:
    print(-1)
    exit()
min_u = float('inf')
max_u = -float('inf')
min_v = float('inf')
max_v = -float('inf')
for x, y in lands:
    u = x + y
    v = x - y
    min_u = min(min_u, u)
    max_u = max(max_u, u)
    min_v = min(min_v, v)
    max_v = max(max_v, v)
ans = float('inf')
for i in range(n):
    for j in range(n):
        if grid[i][j] == 0:
            u = i + j
            v = i - j
            cand1 = max(u - min_u, max_u - u)
            cand2 = max(v - min_v, max_v - v)
            cand = max(cand1, cand2)
            ans = min(ans, cand)
print(ans)
