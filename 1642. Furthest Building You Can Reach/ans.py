import heapq

def furthestBuilding(A, bricks, ladders):
    pq = []
    for i in range(len(A) - 1):
        d = A[i + 1] - A[i]
        if d > 0:
            heapq.heappush(pq, -d)
        if len(pq) > ladders:
            bricks += -heapq.heappop(pq)
            bricks += 1
        bricks -= 1
        if bricks < 0:
            return i
    return len(A) - 1

# Input
n = int(input())
A = list(map(int, input().split()))
bricks, ladders = map(int, input().split())

# Output
print(furthestBuilding(A, bricks, ladders))