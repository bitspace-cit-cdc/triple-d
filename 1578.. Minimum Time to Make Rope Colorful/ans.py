def minCost(colors, neededTime):
    n = len(neededTime)
    f = 1
    ans = 0
    v = [neededTime[0]]
    
    for i in range(1, n):
        if colors[i] == colors[i - 1]:
            v.append(neededTime[i])
            f += 1
        else:
            if f > 2:
                max_val = float('-inf')
                second_max = float('-inf')
                total_time = 0

                for time in v:
                    if time > max_val:
                        second_max = max_val
                        max_val = time
                    elif time > second_max:
                        second_max = time
                    total_time += time
                
                ans += total_time - max_val - second_max
                v.clear()
                v.append(0)
            f = 1
            v[0] = neededTime[i]

    if f > 2:
        max_val = float('-inf')
        second_max = float('-inf')
        total_time = 0

        for time in v:
            if time > max_val:
                second_max = max_val
                max_val = time
            elif time > second_max:
                second_max = time
            total_time += time
        
        ans += total_time - max_val - second_max

    return ans

n = int(input())
colors = input().strip()
neededTime = list(map(int, input().split()))

print(minCost(colors, neededTime))