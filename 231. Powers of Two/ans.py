def solve():
    n, k = map(int, input().split())
    print("true" if bin(n).count('1') == k else "false")

t = int(input())
for _ in range(t):
	solve()