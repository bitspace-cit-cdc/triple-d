#include <bits/stdc++.h>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<TreeNode *>
allPossibleBST(int start, int end,
               map<pair<int, int>, vector<TreeNode *>> &memo) {
  vector<TreeNode *> res;
  if (start > end) {
    res.push_back(nullptr);
    return res;
  }
  if (memo.find(make_pair(start, end)) != memo.end()) {
    return memo[make_pair(start, end)];
  }
  for (int i = start; i <= end; ++i) {
    vector<TreeNode *> leftSubTrees = allPossibleBST(start, i - 1, memo);
    vector<TreeNode *> rightSubTrees = allPossibleBST(i + 1, end, memo);

    for (auto left : leftSubTrees) {
      for (auto right : rightSubTrees) {
        TreeNode *root = new TreeNode(i, left, right);
        res.push_back(root);
      }
    }
  }
  return memo[make_pair(start, end)] = res;
}

vector<TreeNode *> generateTrees(int n) {
  map<pair<int, int>, vector<TreeNode *>> memo;
  return allPossibleBST(1, n, memo);
}

void solve() {
  int n;
  cin >> n;
  vector<TreeNode *> res = generateTrees(n);
  int maxHeight = 0;

  for (auto root : res) {
    queue<TreeNode *> q;
    vector<string> level;
    int height = 0;

    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      height++;

      while (size--) {
        auto node = q.front();
        q.pop();
        level.push_back(node ? to_string(node->val) : "null");
        if (node) {
          q.push(node->left);
          q.push(node->right);
        }
      }
    }

    if (height >= maxHeight) {
      if (height > maxHeight) {
        maxHeight = height;
      }
      while (!level.empty() && level.back() == "null")
        level.pop_back();

      for (const auto &val : level)
        cout << val << " ";
      cout << endl;
      cout << height << endl;
    }
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}