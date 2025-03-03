#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int kthUniquePrimeFactor(int n, int k) {
    vector<int> primes = sieve(n);
    vector<int> factors;

    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            factors.push_back(p);
        }
    }

    if (n > 1) factors.push_back(n);

    if (factors.size() < k) {
        return -1;
    }

    return factors[k - 1];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << kthUniquePrimeFactor(n, k) << endl;
    return 0;
}