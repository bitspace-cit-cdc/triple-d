#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  cout << (__builtin_popcount(n) == k ? "true" : "false") << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}