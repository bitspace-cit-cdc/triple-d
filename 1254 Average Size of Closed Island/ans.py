
def dfs(grid, i, j):
    if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 0:
        return 0
    grid[i][j] = 0
    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1)

def averageIslandSize(grid):
    total_size, count = 0, 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                total_size += dfs(grid, i, j)
                count += 1
    return 0.0 if count == 0 else total_size / count

m, n = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(m)]
print(f"{averageIslandSize(grid):.1f}")
