#include <bits/stdc++.h>

using namespace std;

struct NestedElement {
  bool is_integer;
  int value;
  vector<NestedElement> children;
  NestedElement(int v) : is_integer(true), value(v) {}
  NestedElement(const vector<NestedElement> &c)
      : is_integer(false), value(0), children(c) {}
};

vector<NestedElement> parse(const string &s, size_t &pos) {
  vector<NestedElement> v;
  ++pos;
  while (s[pos] != ']') {
    if (s[pos] == ',')
      ++pos;
    else if (isdigit(s[pos]) || s[pos] == '-') {
      int sign = s[pos] == '-' ? (++pos, -1) : 1;
      int num = 0;
      while (pos < s.size() && isdigit(s[pos]))
        num = num * 10 + (s[pos++] - '0');
      v.emplace_back(sign * num);
    } else if (s[pos] == '[')
      v.emplace_back(parse(s, pos));
  }
  ++pos;
  return v;
}

int sum(const vector<NestedElement> &v, int d) {
  int s = 0;
  for (const auto &e : v)
    s += e.is_integer ? e.value * d : sum(e.children, d + 1);
  return s;
}

int main() {
  string s;
  getline(cin, s);
  s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
  size_t pos = 0;
  cout << sum(parse(s, pos), 1) << endl;
}