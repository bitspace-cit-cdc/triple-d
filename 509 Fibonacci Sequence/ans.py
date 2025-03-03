
x, y, n = map(int, input().split())
if n == 0:
    print(x)
else:
    F_next, F_curr = y, x
    for _ in range(n, 0, -1):
        F_prev = F_next - F_curr
        F_next, F_curr = F_curr, F_prev
    print(F_curr)
