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

class Tree {
  TreeNode *first = nullptr;
  TreeNode *second = nullptr;
  TreeNode *prev = nullptr;

public:
  void recoverTree(TreeNode *root) {
    inorderTraversal(root);
    if (first && second) {
      swap(first->val, second->val);
    }
  }

  void inorderTraversal(TreeNode *root) {
    if (!root)
      return;

    inorderTraversal(root->left);

    if (prev && root->val > prev->val) {
      if (!first) {
        first = prev;
      }
      second = root;
    }
    prev = root;

    inorderTraversal(root->right);
  }
};

TreeNode *buildTree(const vector<string> &parts) {
  if (parts.empty() || parts[0] == "null")
    return nullptr;

  TreeNode *root = new TreeNode(stoi(parts[0]));
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < parts.size()) {
    TreeNode *curr = q.front();
    q.pop();

    if (i < parts.size()) {
      string val = parts[i];
      if (val != "null") {
        curr->left = new TreeNode(stoi(val));
        q.push(curr->left);
      }
      i++;
    }

    if (i < parts.size()) {
      string val = parts[i];
      if (val != "null") {
        curr->right = new TreeNode(stoi(val));
        q.push(curr->right);
      }
      i++;
    }
  }

  return root;
}

vector<string> serializeTree(TreeNode *root) {
  vector<string> res;
  if (!root)
    return res;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    if (curr) {
      res.push_back(to_string(curr->val));
      q.push(curr->left);
      q.push(curr->right);
    } else {
      res.push_back("null");
    }
  }

  while (!res.empty() && res.back() == "null") {
    res.pop_back();
  }

  return res;
}

void solve() {
  string line;
  getline(cin, line);

  vector<string> parts;
  stringstream ss(line);
  string part;
  while (ss >> part) {
    parts.push_back(part);
  }

  TreeNode *root = buildTree(parts);

  Tree tree;
  tree.recoverTree(root);

  vector<string> res = serializeTree(root);

  for (auto x : res) {
    cout << x << " ";
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    solve();
  }

  return 0;
}