def findTheCity(n, edges, distanceThreshold):
    INF = float('inf')
    dist = [[INF] * n for _ in range(n)]

    for fromi, toi, weight in edges:
        dist[fromi][toi] = weight

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    min_neighbors = float('inf')
    best_city = -1

    for i in range(n):
        count = sum(1 for j in range(n) if i != j and dist[i][j] <= distanceThreshold)
        if count < min_neighbors or (count == min_neighbors and i > best_city):
            min_neighbors = count
            best_city = i

    return best_city


n = int(input().strip())
m = int(input().strip())
edges = [list(map(int, input().split())) for _ in range(m)]
distanceThreshold = int(input().strip())
print(findTheCity(n, edges, distanceThreshold))