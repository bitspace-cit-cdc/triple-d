#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  int n;
  cin >> s >> n;
  bool flag = false;
  if (n < 0)
    flag = true;
  n = abs(n);
  if (n == 0) {
    cout << s << endl;
    return;
  }
  if (n == 1) {
    cout << s << endl;
    return;
  }
  vector<string> v(n);
  int i = 0;
  bool down = true;
  for (char c : s) {
    v[i] += c;
    if (down) {
      i++;
    } else {
      i--;
    }
    if (i == n - 1) {
      down = false;
    }
    if (i == 0) {
      down = true;
    }
  }
  string ans;
  if (flag)
    reverse(v.begin(), v.end());

  for (string x : v) {
    ans += x;
  }
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}