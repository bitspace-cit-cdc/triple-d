def solve():
    s = input().strip()
    n = int(input())
    flag = False
    if n < 0:
        flag = True
    n = abs(n)

    if n == 0 or n == 1:
        print(s)
        return

    v = [""] * n
    i = 0
    down = True

    for c in s:
        v[i] += c
        if down:
            i += 1
        else:
            i -= 1
        if i == n - 1:
            down = False
        if i == 0:
            down = True

    if flag:
        v.reverse()

    ans = "".join(v)
    print(ans)


t = int(input())
for _ in range(t):
    solve()