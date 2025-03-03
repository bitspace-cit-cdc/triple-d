import sys
from collections import deque

def solve(forbidden, a, b, x):
    forb = set(forbidden)
    max_forbidden = max(forb) if forb else 0
    upper_bound = max(x, max_forbidden) + a + b + 1000
    q = deque([(0, False, False, 0)])
    visited = {(0, False, False)}
    while q:
        pos, usedSpecial, lastBackward, jumps = q.popleft()
        if pos == x:
            return jumps
        nextPos = pos + a
        if nextPos <= upper_bound and nextPos not in forb:
            state = (nextPos, usedSpecial, False)
            if state not in visited:
                visited.add(state)
                q.append((nextPos, usedSpecial, False, jumps + 1))
        if not usedSpecial:
            specialPos = pos + 2 * a
            if specialPos <= upper_bound and specialPos not in forb:
                state = (specialPos, True, False)
                if state not in visited:
                    visited.add(state)
                    q.append((specialPos, True, False, jumps + 1))
        if not lastBackward:
            backPos = pos - b
            if backPos >= 0 and backPos not in forb:
                state = (backPos, usedSpecial, True)
                if state not in visited:
                    visited.add(state)
                    q.append((backPos, usedSpecial, True, jumps + 1))
    return -1

if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        arr = list(map(int, sys.stdin.readline().split()))
        a, b, x = map(int, sys.stdin.readline().split())
        print(solve(arr, a, b, x))