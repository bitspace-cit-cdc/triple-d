#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = false;
		isPrime[1] = true;
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int minDeletions(string s) {
    int maxFreq = s.size();
    vector<bool> isPrime = sieveOfEratosthenes(maxFreq);

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    unordered_set<int> seen;
    int deletions = 0;

    for (auto& [ch, f] : freq) {
        while (f > 0 && (!isPrime[f] || seen.count(f))) {
            f--;
            deletions++;
        }

        if (f > 0 && !seen.count(f) && isPrime[f]) {
            seen.insert(f);
        } else if (f == 0) {
            deletions++;
        }
    }

    return deletions;
}

int main() {
    string s;
    cin >> s;
    cout << minDeletions(s) << endl;
    return 0;
}