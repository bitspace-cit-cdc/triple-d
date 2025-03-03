from bisect import bisect_left, bisect_right

def searchRange(nums, target):
    startingPosition = bisect_left(nums, target)
    endingPosition = bisect_left(nums, target + 1) - 1
    if startingPosition < len(nums) and nums[startingPosition] == target:
        return endingPosition - startingPosition + 1
    return 0

n, k = map(int, input().split())
nums = list(map(int, input().split()))

print(searchRange(nums, k))