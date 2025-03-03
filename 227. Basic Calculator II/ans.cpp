#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  getline(cin, s);
  s.erase(remove_if(s.begin(), s.end(),
                    [](char c) {
                      return !isdigit(c) && c != '+' && c != '-' && c != '*' &&
                             c != '/';
                    }),
          s.end());
  int cur = 0, ans = 0, interimRes = 0;
  char prevOp = '+';
  s += "##";
  for (auto c : s)
    if (isdigit(c))
      cur = cur * 10 + (c - '0');
    else {
      if (prevOp == '*')
        interimRes *= cur;
      else if (prevOp == '/')
        interimRes /= cur;
      else
        ans += interimRes, interimRes = prevOp == '+' ? cur : -cur;
      prevOp = c;
      cur = 0;
    }

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;
  cin.ignore();
  while (t--) {
    solve();
  }
  return 0;
}