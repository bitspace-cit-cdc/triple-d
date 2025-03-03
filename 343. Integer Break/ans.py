def integerBreak(n):
    if n == 2:
        return 1
    if n == 3:
        return 2

    n3 = n // 3
    rem = n % 3

    if rem == 1:
        rem = 4
        n3 -= 1
    elif rem == 0:
        rem = 1

    c = 1
    for _ in range(n3):
        c = (c * 3) % 1000000007

    return (c * rem) % 1000000007

n = int(input())
result = integerBreak(n)
print(result)