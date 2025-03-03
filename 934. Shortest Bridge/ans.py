def shortestBridge(grid, m):
    n = len(grid)
    firstX, firstY = -1, -1

    for i in range(n):
        for j in range(n):
            if grid[i][j] == 1:
                firstX, firstY = i, j
                break

    bfsQue, secondBfsQue = [(firstX, firstY)], [(firstX, firstY)]
    grid[firstX][firstY] = 2

    while bfsQue:
        newBfs = []
        for x, y in bfsQue:
            for dx, dy in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
                if 0 <= dx < n and 0 <= dy < n and grid[dx][dy] == 1:
                    newBfs.append((dx, dy))
                    secondBfsQue.append((dx, dy))
                    grid[dx][dy] = 2
        bfsQue = newBfs

    distance = 0
    while secondBfsQue:
        newBfs = []
        for x, y in secondBfsQue:
            for dx, dy in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
                if 0 <= dx < n and 0 <= dy < n:
                    if grid[dx][dy] == 1:
                        return distance
                    elif grid[dx][dy] == 0:
                        newBfs.append((dx, dy))
                        grid[dx][dy] = -1
        secondBfsQue = newBfs
        distance += 1
    
    return distance if distance <= m else -1

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

print(shortestBridge(grid, m))