def sieve(n):
    is_prime = [True] * (n + 1)
    primes = []
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return primes

def kthUniquePrimeFactor(n, k):
    primes = sieve(n)
    factors = []

    for p in primes:
        if p * p > n:
            break
        if n % p == 0:
            factors.append(p)

    if n > 1:
        factors.append(n)

    if len(factors) < k:
        return -1

    return factors[k - 1]

n, k = map(int, input().split())
print(kthUniquePrimeFactor(n, k))