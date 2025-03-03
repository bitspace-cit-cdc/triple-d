#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  stack<pair<char, int>> st;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push({s[i], i});
    } else {
      if (st.empty()) {
        cout << 0 << endl;
        return;
      }
      auto top = st.top();
      if ((s[i] == ')' && top.first == '(') ||
          (s[i] == '}' && top.first == '{') ||
          (s[i] == ']' && top.first == '[')) {
        ans = max(ans, i - top.second + 1);
        st.pop();
      } else {
        cout << 0 << endl;
        return;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}