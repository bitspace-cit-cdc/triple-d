
#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
 
int sumOfLeftNodes(TreeNode* root, bool isLeft) {
    if(!root) return 0;
    int sum = (isLeft ? root->val : 0);
    sum += sumOfLeftNodes(root->left, true);
    sum += sumOfLeftNodes(root->right, false);
    return sum;
}
 
int main(){
    string line;
    getline(cin, line);
    TreeNode* root = buildTree(line);
    cout << sumOfLeftNodes(root, false);
    return 0;
}
