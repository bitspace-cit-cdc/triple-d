#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), mid(nullptr), right(nullptr) {}
};

unordered_map<TreeNode*, pair<int, int>> dp;

pair<int, int> dfs(TreeNode* root) {
    if (!root) return {0, 0};
    if (dp.count(root)) return dp[root];

    auto left = dfs(root->left);
    auto mid = dfs(root->mid);
    auto right = dfs(root->right);

    int rob = root->val + left.second + mid.second + right.second;
    int skip = max(left.first, left.second) + 
               max(mid.first, mid.second) + 
               max(right.first, right.second);

    return dp[root] = {rob, skip}; 
}

int rob(TreeNode* root) {
    auto res = dfs(root);
    return max(res.first, res.second);
}

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nodes[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->mid = new TreeNode(nodes[i]);
            q.push(curr->mid);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);
    cout << rob(root) << endl;

    return 0;
}