#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
  queue<int> que;
  int summation = 0;
  void push(int x) {
    que.push(x);
    summation += x;
    for (int i = 0; i < que.size() - 1; ++i) {
      que.push(que.front());
      que.pop();
    }
  }

  int pop() {
    int res = que.front();
    que.pop();
    summation -= res;
    return res;
  }

  int top() { return que.front(); }

  bool empty() { return que.empty(); }
  int size() { return que.size(); }
  int sum() { return summation; }
};

void solve() {
  string s1, s2;
  cin.ignore();
  getline(cin, s1);
  getline(cin, s2);
  stringstream ss1(s1);
  stringstream ss2(s2);
  string command;
  int num;
  ss1 >> command;
  ss2 >> num;
  if (command != "MyStack") {
    return;
  }
  MyStack stack;
  cout << "null" << " ";
  while (ss1 >> command) {
    int x;
    ss2 >> x;
    if (command == "push") {
      stack.push(x);
      cout << "null" << " ";
    } else if (command == "pop") {
      cout << stack.pop() << " ";
    } else if (command == "top") {
      cout << stack.top() << " ";
    } else if (command == "empty") {
      cout << (stack.empty() ? "true" : "false") << " ";
    } else if (command == "size") {
      cout << stack.size() << " ";
    } else if (command == "sum") {
      cout << stack.sum() << " ";
    }
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}