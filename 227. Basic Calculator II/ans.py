def solve():
    s = input().strip()
    s = "".join(c for c in s if c.isdigit() or c in "+-*/")

    cur = 0
    ans = 0
    interimRes = 0
    prevOp = "+"
    s += "##"

    for c in s:
        if c.isdigit():
            cur = cur * 10 + int(c)
        else:
            if prevOp == "*":
                interimRes *= cur
            elif prevOp == "/":
                interimRes //= cur
            else:
                ans += interimRes
                interimRes = cur if prevOp == "+" else -cur
            prevOp = c
            cur = 0

    print(ans)


t = int(input())
for _ in range(t):
    solve()