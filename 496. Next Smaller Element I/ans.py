def nextGreaterElement(nums1, nums2):
    mpp = {}
    stack = []

    for num in reversed(nums2):
        while stack and stack[-1] >= num:
            stack.pop()
        mpp[num] = stack[-1] if stack else -1
        stack.append(num)

    return [mpp[num] for num in nums1]

n = int(input())
nums1 = list(map(int, input().split()))
m = int(input())
nums2 = list(map(int, input().split()))

result = nextGreaterElement(nums1, nums2)
print(*result)