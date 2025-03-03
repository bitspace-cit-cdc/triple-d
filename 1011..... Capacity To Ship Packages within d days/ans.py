def day_taken(weights, mid):
    n_days = 1
    left = mid
    c = 0
    for i in range(len(weights)):
        if weights[i] + c > left:
            n_days += 1
            c += 1
            left = mid - weights[i] - c
            if left < 0:
                return float('inf')
        else:
            left -= (weights[i] - c)
    return n_days


def ship_within_days(weights, days):
    low = max(weights)
    high = sum(weights)
    ans = -1

    while low <= high:
        mid = low + (high - low) // 2
        n_days = day_taken(weights, mid)
        if n_days <= days:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans


n, days = map(int, input().split())
weights = list(map(int, input().split()))

print(ship_within_days(weights, days))