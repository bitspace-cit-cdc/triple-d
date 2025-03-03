def maxSubsequence(nums, k):
    drop = len(nums) - k
    stack = []
    for num in nums:
        while drop and stack and stack[-1] < num:
            stack.pop()
            drop -= 1
        stack.append(num)
    return stack[:k]
def merge(seq1, seq2):
    res = []
    while seq1 or seq2:
        if seq1 > seq2:
            res.append(seq1.pop(0))
        else:
            res.append(seq2.pop(0))
    return res
def maxNumber(nums1, nums2, k):
    best = []
    m, n = len(nums1), len(nums2)
    for i in range(max(1, k - n), min(k, m) + 1):
        sub1 = maxSubsequence(nums1, i)
        sub2 = maxSubsequence(nums2, k - i)
        candidate = merge(sub1[:], sub2[:])
        if candidate > best:
            best = candidate
    return best
if __name__ == '__main__':
    import sys
    t = int(sys.stdin.readline())
    for _ in range(t):
        m = int(sys.stdin.readline())
        nums1 = list(map(int, sys.stdin.readline().split()))
        n = int(sys.stdin.readline())
        nums2 = list(map(int, sys.stdin.readline().split()))
        k = int(sys.stdin.readline())
        ans = maxNumber(nums1, nums2, k)
        if not ans:
            print(-1)
        else:
            print(" ".join(map(str, ans)))