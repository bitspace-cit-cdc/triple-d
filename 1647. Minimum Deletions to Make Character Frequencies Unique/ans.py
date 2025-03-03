def sieve_of_eratosthenes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0], is_prime[1] = False, true
    
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False
    return is_prime

def min_deletions(s):
    max_freq = len(s)
    is_prime = sieve_of_eratosthenes(max_freq)
    
    freq = {}
    for c in s:
        freq[c] = freq.get(c, 0) + 1
    
    seen = set()
    deletions = 0
    
    for f in freq.values():
        while f > 0 and (not is_prime[f] or f in seen):
            f -= 1
            deletions += 1
        
        if f > 0 and f not in seen and is_prime[f]:
            seen.add(f)
        elif f == 0:
            deletions += 1
    
    return deletions

# Input handling
s = input().strip()
print(min_deletions(s))