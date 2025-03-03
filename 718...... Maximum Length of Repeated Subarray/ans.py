def findLength(nums1, nums2):
    m, n = len(nums1), len(nums2)
    dp = [[[0, 0] for _ in range(n + 1)] for _ in range(m + 1)]
    max_len = 0
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if nums1[i - 1] == nums2[j - 1]:
                dp[i][j][0] = dp[i - 1][j - 1][0] + 1
                dp[i][j][1] = dp[i - 1][j - 1][1] + nums1[i - 1]
                if dp[i][j][1] % 2 == 0:
                    max_len = max(max_len, dp[i][j][0])

    return max_len

n = int(input())
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))

result = findLength(nums1, nums2)
print(result)