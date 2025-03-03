
n = int(input())
nums = list(map(int, input().split()))
k = int(input())
nums.sort()
c = 0
for i in range(len(nums)-1, 1, -1):
    if nums[i] - nums[i-1] <= k:
        c = nums[i] * nums[i-1] * nums[i-2]
        break
print(c)
