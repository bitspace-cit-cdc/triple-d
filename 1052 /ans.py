def maxSatisfied(customers, grumpy, minutes):
    n = len(customers)
    ans = 0
    for i in range(n):
        if grumpy[i] == 0:
            ans += customers[i]
    
    unsatis = 0
    for i in range(minutes):
        if grumpy[i] == 1:
            unsatis += customers[i]
    
    max_unsatis = unsatis
    for i in range(minutes, n):
        if grumpy[i - minutes] == 1:
            unsatis -= customers[i - minutes]
        if grumpy[i] == 1:
            unsatis += customers[i]
        max_unsatis = max(max_unsatis, unsatis)
    
    return ans + max_unsatis

n = int(input())
customers = list(map(int, input().split()))
grumpy = list(map(int, input().split()))
minutes = int(input())

print(maxSatisfied(customers, grumpy, minutes))