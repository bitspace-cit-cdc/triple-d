def countNegatives(grid):
    m, n = len(grid), len(grid[0])
    r, c, cnt = m - 1, 0, 0
    while r >= 0 and c < n:
        if grid[r][c] < 0:
            r -= 1
            cnt += n - c
        else:
            c += 1
    return cnt

m, n = map(int, input().split())
grid = []
for _ in range(m):
    grid.append(list(map(int, input().split())))

print(countNegatives(grid))