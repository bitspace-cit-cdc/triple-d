def maxScore(cardPoints, k, m):
    n = len(cardPoints)
    max_points = 0

    for left in range(min(m, k) + 1):
        right = k - left
        if right > min(m, k):
            continue

        left_sum = sum(cardPoints[:left])
        right_sum = sum(cardPoints[-right:]) if right > 0 else 0
        max_points = max(max_points, left_sum + right_sum)

    return max_points

cardPoints = list(map(int, input().split()))
k, m = map(int, input().split())
print(maxScore(cardPoints, k, m))