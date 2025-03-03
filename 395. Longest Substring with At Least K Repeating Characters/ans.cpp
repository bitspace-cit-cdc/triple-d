#include <bits/stdc++.h>
using namespace std;

string longestSubstring(string s, int k) {
  if (s.empty() || k > s.size()) {
    return "";
  }

  unordered_map<char, int> charCount;
  for (char c : s) {
    charCount[c]++;
  }

  string sub1 = "", sub2 = "";
  for (int i = 0; i < s.size(); ++i) {
    if (charCount[s[i]] < k) {
      sub1 = longestSubstring(s.substr(0, i), k);
      sub2 = longestSubstring(s.substr(i + 1), k);
      break;
    }
  }

  if (sub1.empty() && sub2.empty()) {
    return s;
  }

  return sub1.size() > sub2.size() ? sub1 : sub2;
}
void solve() {
  string s;
  int k;
  cin >> s;
  cin >> k;
  cout << longestSubstring(s, k) << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}