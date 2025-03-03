
def dfs(g, i, j):
    if min(i, j) < 0 or max(i, j) >= len(g) or g[i][j] != 0:
        return 0
    g[i][j] = 1
    return 1 + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j - 1) + dfs(g, i, j + 1)

def regionsBySlashes(grid):
    n = len(grid)
    g = [[0] * (n * 3) for _ in range(n * 3)]
    regions = 0
    
    for i in range(n):
        for j in range(n):
            if grid[i][j] == '/':
                g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1
            elif grid[i][j] == '\\':
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1
            elif grid[i][j] == 'X':
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1
                g[i * 3][j * 3 + 2] = g[i * 3 + 2][j * 3] = 1

    for i in range(n * 3):
        for j in range(n * 3):
            if dfs(g, i, j):
                regions += 1

    return regions

n = int(input())
grid = [input().strip() for _ in range(n)]
print(regionsBySlashes(grid))
