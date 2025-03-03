#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin.ignore();
  getline(cin, s);
  stack<int> st;
  int result = 0;
  int num = 0;
  int sign = 1;
  int openParentheses = 0;
  bool lastWasOperator = true;
  for (int i = 0; i < s.length(); ++i) {
    char ch = s[i];

    if (ch == ' ')
      continue;

    if (isdigit(ch)) {
      num = (num * 10) + (ch - '0');
      lastWasOperator = false;
    } else if (ch == '+' || ch == '-') {
      if (lastWasOperator) {
        cout << "invalid" << endl;
        return;
      }
      result += (sign * num);
      sign = (ch == '+') ? 1 : -1;
      num = 0;
      lastWasOperator = true;
    } else if (ch == '(') {
      if (!lastWasOperator) {
        cout << "invalid" << endl;
        return;
      }
      st.push(result);
      st.push(sign);
      result = 0;
      sign = 1;
      openParentheses++;
      lastWasOperator = false;
    } else if (ch == ')') {
      if (openParentheses == 0 || lastWasOperator) {
        cout << "invalid" << endl;
        return;
      }
      result += (sign * num);
      sign = st.top();
      st.pop();
      result *= sign;
      result += st.top();
      st.pop();
      num = 0;
      openParentheses--;
      lastWasOperator = false;
    } else {
      cout << "invalid" << endl;
      return;
    }
  }

  if (openParentheses != 0 || lastWasOperator) {
    cout << "invalid" << endl;
    return;
  }

  result += (sign * num);
  cout << to_string(result) << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
	  }

  return 0;
}