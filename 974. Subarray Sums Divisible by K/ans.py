from collections import defaultdict

def subarraysDivByK(nums, k):
    n = len(nums)
    ans = []
    pre = [0] * n
    pre[0] = nums[0]
    
    for i in range(1, n):
        pre[i] = pre[i - 1] + nums[i]
    
    mp = defaultdict(int)
    mp[0] = 1
    c = 0
    
    for i in pre:
        c += mp[(k + i % k) % k]
        mp[(k + i % k) % k] += 1
        ans.append(c)
    
    return ans

n = int(input())
nums = list(map(int, input().split()))
k = int(input())
query = list(map(int, input().split()))

ans = subarraysDivByK(nums, k)

for i in query:
	print(ans[i], end=" ")
print()