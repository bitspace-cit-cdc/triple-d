def minimum_size(nums, k):
    l, r = 1, max(nums)
    while l < r:
        m = l + (r - l) // 2
        cnt = sum((num - 1) // m for num in nums)
        if cnt <= k:
            r = m
        else:
            l = m + 1
    return r

def remove_max_element(nums):
    nums.remove(max(nums))


n = int(input())
nums = list(map(int, input().split()))
k = int(input())

remove_max_element(nums)
result = minimum_size(nums, k)
print(result)