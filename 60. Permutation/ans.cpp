#include <bits/stdc++.h>

using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int rank = 1;

  vector<long long> fact(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  set<char> chars(s.begin(), s.end());

  for (int i = 0; i < n; ++i) {
    auto it = chars.begin();
    int count = 0;
    while (*it != s[i]) {
      count++;
      it++;
    }

    rank += count * fact[n - i - 1];

    chars.erase(s[i]);
  }

  cout << rank << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}