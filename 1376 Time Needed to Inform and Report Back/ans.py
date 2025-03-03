
def dfs(node):
    if not children[node]:
        return 0
    max_sub = 0
    for child in children[node]:
        max_sub = max(max_sub, dfs(child))
    return informTime[node] + max_sub

n, headID = map(int, input().split())
manager = list(map(int, input().split()))
informTime = list(map(int, input().split()))
children = [[] for _ in range(n)]
for i in range(n):
    if manager[i] != -1:
        children[manager[i]].append(i)

max_inform_sum = dfs(headID)
print(2 * max_inform_sum)
