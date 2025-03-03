def runningSum(nums):
    result = []
    current_sum = 0

    for num in nums:
        current_sum += num
        result.append(current_sum)
        if current_sum < 0:
            current_sum = 0
    
    return result

# Example usage
nums = list(map(int, input().split()))
print(runningSum(nums))