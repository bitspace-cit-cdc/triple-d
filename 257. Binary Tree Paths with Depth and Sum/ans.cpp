
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* node, string path, int depth, int sum, vector<tuple<string, int, int>>& result) {
    if (!node) return;
    if (!path.empty()) path += "->";
    path += to_string(node->val);
    sum += node->val;
    if (!node->left && !node->right) {
        result.push_back({path, depth, sum});
        return;
    }
    dfs(node->left, path, depth + 1, sum, result);
    dfs(node->right, path, depth + 1, sum, result);
}

vector<tuple<string, int, int>> binaryTreePaths(TreeNode* root) {
    vector<tuple<string, int, int>> result;
    dfs(root, "", 1, 0, result);
    return result;
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    TreeNode* root = buildTree(nodes);
    vector<tuple<string, int, int>> result = binaryTreePaths(root);
    for (auto& [path, depth, sum] : result) {
        cout << path << " " << depth << " " << sum << "\n";
    }
    return 0;
}
