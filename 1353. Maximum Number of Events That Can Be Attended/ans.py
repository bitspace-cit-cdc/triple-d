import heapq

def maxEvents(events, k):
    events.sort()
    pq = []
    res = 0
    i = 0
    n = len(events)
    
    for d in range(1, 100001):
        x = k
        while pq and pq[0] < d:
            heapq.heappop(pq)
        
        while i < n and events[i][0] == d:
            heapq.heappush(pq, events[i][1])
            i += 1
        
        while x > 0 and pq:
            heapq.heappop(pq)
            res += 1
            x -= 1
    
    return res

n, k = map(int, input().split())
events = [list(map(int, input().split())) for _ in range(n)]

print(maxEvents(events, k))