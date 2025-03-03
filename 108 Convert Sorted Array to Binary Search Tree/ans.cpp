
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, mid + 1, r);
    root->right = sortedArrayToBST(nums, l, mid - 1);
    return root;
}

vector<string> levelOrder(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            res.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            res.push_back("null");
        }
    }
    while (!res.empty() && res.back() == "null")
        res.pop_back();
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    TreeNode* root = sortedArrayToBST(nums, 0, n - 1);
    vector<string> ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ",";
    }
    return 0;
}
