def dfs(i, rooms, visited):
    global c
    c += 1
    visited[i] = True
    for j in rooms[i]:
        if not visited[j]:
            dfs(j, rooms, visited)

def canVisitAllRooms(rooms):
    global c
    n = len(rooms)
    visited = [False] * n
    c = 0
    dfs(0, rooms, visited)
    
    for i in range(n):
        if visited[i]:
            dfs(i, rooms, visited)
            break
            
    return c == n

n = int(input())
rooms = []
for _ in range(n):
    room = list(map(int, input().split()))
    rooms.append(room[1:])

if canVisitAllRooms(rooms):
    print(True)
else:
    print(False)