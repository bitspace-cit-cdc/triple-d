#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  stack<string> st;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    string temp = "";
    while (i < s.size() && s[i] != '/') {
      temp += s[i];
      i++;
    }
    if (temp[0] == '.' && temp.size() % 2 == 0) {
      int count = temp.size() / 2;
      while (count--) {
        if (!st.empty()) {
          st.pop();
        }
      }
    } else if (temp == "." || temp == "") {
      continue;
    } else {
      st.push(temp);
    }
  }
  while (!st.empty()) {
    ans = "/" + st.top() + ans;
    st.pop();
  }
  if (ans == "") {
    ans = "/";
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}