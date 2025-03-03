def findNSE(arr, n):
    nse = [n] * n
    stack = []

    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] <= arr[i]:
            stack.pop()
        nse[i] = stack[-1] if stack else n
        stack.append(i)
    
    return nse

def findPSEE(arr, n):
    psee = [-1] * n
    stack = []

    for i in range(n):
        while stack and arr[stack[-1]] < arr[i]:
            stack.pop()
        psee[i] = stack[-1] if stack else -1
        stack.append(i)

    return psee

def sumSubarrayMaxs(arr):
    mod = 10**9 + 7
    n = len(arr)
    
    nse = findNSE(arr, n)
    psee = findPSEE(arr, n)
    
    total = 0
    for i in range(n):
        left = i - psee[i]
        right = nse[i] - i
        freq = left * right
        total = (total + (freq * arr[i]) % mod) % mod
    
    return total

n = int(input())
arr = list(map(int, input().split()))

print(sumSubarrayMaxs(arr))