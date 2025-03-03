
n = int(input())
nums = list(map(int, input().split()))
k, s = map(int, input().split())
from collections import Counter
cnt = Counter(nums)
ans = 0
if k == 0:
    for x, freq in cnt.items():
        if freq >= 2 and 2 * x <= s:
            ans += 1
else:
    for x in cnt:
        y = x + k
        if y in cnt and (x + y) <= s:
            ans += 1
print(ans)
