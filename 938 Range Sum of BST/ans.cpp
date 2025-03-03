
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const string &s) {
    if (s.empty()) return NULL;
    vector<string> nodes;
    istringstream iss(s);
    string token;
    while (iss >> token) {
        nodes.push_back(token);
    }
    if (nodes.size() == 0) return NULL;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != "null") {
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

int rangeSum(TreeNode* root, int low, int high, int k, int height) {
    if (!root || height >= k) return 0;
    int s = 0;
    if (root->val >= low && root->val <= high)
        s += root->val;
    s += rangeSum(root->left, low, high, k, height + 1);
    s += rangeSum(root->right, low, high, k, height + 1);
    return s;
}

int main() {
    string treeStr;
    getline(cin, treeStr);
    TreeNode* root = buildTree(treeStr);
    int low, high, k;
    cin >> low >> high >> k;
    cout << rangeSum(root, low, high, k, 0);
    return 0;
}
