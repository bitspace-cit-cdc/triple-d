def numPairs(n, time):
    v = [0] * 60
    v1 = [0] * 50
    v2 = [0] * 300
    
    ans = 0
    
    for i in range(len(time) - 1, -1, -1):
        ans += v[(60 - time[i] % 60) % 60]
        v[time[i] % 60] += 1
        
        ans += v1[(50 - time[i] % 50) % 50]
        v1[time[i] % 50] += 1
        
        ans -= v2[(300 - time[i] % 300) % 300]
        v2[time[i] % 300] += 1
    
    return ans

n = int(input())
time = list(map(int, input().split()))
print(numPairs(n, time))