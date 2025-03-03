def check_subarray_sum(nums, k, l):
    n = len(nums)
    total = sum(nums[:l])
    if total % k == 0:
        return True
    
    for i in range(l, n):
        total += nums[i] - nums[i - l]
        if total % k == 0:
            return True
    
    return False

n = int(input())
nums = list(map(int, input().split()))
k, l = map(int, input().split())
print("true" if check_subarray_sum(nums, k, l) else "false")
