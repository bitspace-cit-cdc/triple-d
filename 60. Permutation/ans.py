def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

def lexicographicalRank(s):
    n = len(s)
    rank = 1
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i
    
    chars = sorted(list(s))
    
    for i in range(n):
        idx = chars.index(s[i])
        rank += idx * fact[n - i - 1]
        chars.pop(idx)
    
    return rank