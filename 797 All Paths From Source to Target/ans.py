def dfs(graph, path, res, cur, edges, k):
    path.append(cur)
    if cur == len(graph) - 1:
        if edges <= k:
            res.append(path.copy())
    if edges < k:
        for nxt in graph[cur]:
            dfs(graph, path, res, nxt, edges + 1, k)
    path.pop()

n = int(input().strip())
graph = [[] for _ in range(n + 1)]
for i in range(n):
    line = input().strip()
    if line:
        nums = list(map(int, line.split()))
        graph[i].extend(nums)
k = int(input().strip())
res = []
path = []
dfs(graph, path, res, 0, 0, k)
for p in res:
    print(" ".join(map(str, p)))
