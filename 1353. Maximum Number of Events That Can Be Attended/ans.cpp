#include <bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>> &A, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  sort(A.begin(), A.end());
  int i = 0, res = 0, n = A.size();
  for (int d = 1; d <= 100000; ++d) {
    int x = k;
    while (pq.size() && pq.top() < d)
      pq.pop();
    while (i < n && A[i][0] == d)
      pq.push(A[i++][1]);
    while (x-- and pq.size()) {
      pq.pop();
      ++res;
    }
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> events(n, vector<int>(2));

  for (int i = 0; i < n; ++i)
    cin >> events[i][0] >> events[i][1];

  cout << maxEvents(events, k) << endl;

  return 0;
}