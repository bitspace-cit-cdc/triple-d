
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cin >> k;
  sort(nums.begin(), nums.end());
  int c = 0;
  for (int i = nums.size() - 1; i >= 2; i--) {
    if (nums[i] - nums[i - 1] <= k) {
      c = nums[i] * nums[i - 1] * nums[i - 2];
      break;
    }
  }
  cout << c;
  return 0;
}
