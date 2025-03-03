def dfs(i, isConnected, visited, c):
    c[0] += 1
    visited[i] = True
    for j in range(len(isConnected)):
        if i != j and isConnected[i][j] == 1 and not visited[j]:
            dfs(j, isConnected, visited, c)

def findProvinces(isConnected, k):
    cities = len(isConnected)
    visited = [False] * cities
    provinces = 0

    for i in range(cities):
        if not visited[i]:
            c = [0]
            dfs(i, isConnected, visited, c)
            if c[0] >= k:
                provinces += 1

    return provinces


n, k = map(int, input().split())

isConnected = [list(map(int, input().split())) for _ in range(n)]

print(findProvinces(isConnected, k))