/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
    if (root == nullptr){
        return res;
    } 

    queue<TreeNode*> level;
    level.push(root);
    while (!level.empty()) {
        int n = level.size();

        // only append the first node we encounter since it's the rightmost
        res.emplace_back(level.front()->val);
        for (int i = 0; i < n; i++) {
            TreeNode* node = level.front();
            if (node->right) level.push(node->right);
            if (node->left) level.push(node->left);
            level.pop();
        }
    }
    return res;
    }
};