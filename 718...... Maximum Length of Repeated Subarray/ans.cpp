#include <bits/stdc++.h>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size(), n = nums2.size();

  vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
  int max_len = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
				dp[i][j][1] = dp[i - 1][j - 1][1] + nums1[i - 1];
        if(dp[i][j][1]%2==0)max_len = max(max_len, dp[i][j][0]);
      }
    }
  }

  return max_len;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> nums1(n), nums2(n);
  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> nums2[i];
  }

  int result = findLength(nums1, nums2);
  cout << result << endl;
  return 0;
}