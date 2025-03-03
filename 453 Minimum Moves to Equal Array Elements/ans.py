
def minMoves(nums):
    nums.sort()
    median = nums[len(nums) // 2]
    return sum(abs(num - median) for num in nums)

n=int(input())
nums = list(map(int, input().split()))
print(minMoves(nums))
