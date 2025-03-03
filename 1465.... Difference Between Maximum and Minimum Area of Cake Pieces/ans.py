
mod = 10**9 + 7
h, w = map(int, input().split())
n, m = map(int, input().split())
horizontal = list(map(int, input().split()))
vertical = list(map(int, input().split()))
horizontal.sort()
vertical.sort()
max_h = max(horizontal[0], h - horizontal[-1])
min_h = min(horizontal[0], h - horizontal[-1])
for i in range(1, len(horizontal)):
    diff = horizontal[i] - horizontal[i - 1]
    max_h = max(max_h, diff)
    min_h = min(min_h, diff)
max_v = max(vertical[0], w - vertical[-1])
min_v = min(vertical[0], w - vertical[-1])
for i in range(1, len(vertical)):
    diff = vertical[i] - vertical[i - 1]
    max_v = max(max_v, diff)
    min_v = min(min_v, diff)
max_area = (max_h % mod) * (max_v % mod) % mod
min_area = (min_h % mod) * (min_v % mod) % mod
ans = (max_area - min_area) % mod
print(ans)
