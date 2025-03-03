
#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
 
TreeNode* buildTree(const string &s) {
    if(s.empty()) return nullptr;
    istringstream iss(s);
    vector<string> tokens;
    string token;
    while(iss >> token) {
        tokens.push_back(token);
    }
    if(tokens.empty()) return nullptr;
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < tokens.size()){
        TreeNode* node = q.front();
        q.pop();
        if(i < tokens.size() && tokens[i] != "null"){
            node->left = new TreeNode(stoi(tokens[i]));
            q.push(node->left);
        }
        i++;
        if(i < tokens.size() && tokens[i] != "null"){
            node->right = new TreeNode(stoi(tokens[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}
 
int maxDiff = 0;
 
void dfs(TreeNode* root) {
    if(!root) return;
    if(root->left)
        maxDiff = max(maxDiff, abs(root->val - root->left->val));
    if(root->right)
        maxDiff = max(maxDiff, abs(root->val - root->right->val));
    dfs(root->left);
    dfs(root->right);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    TreeNode* root = buildTree(line);
    dfs(root);
    cout << maxDiff;
    return 0;
}
