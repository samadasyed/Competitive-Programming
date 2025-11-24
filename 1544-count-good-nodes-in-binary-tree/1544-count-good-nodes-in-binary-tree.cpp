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

int dfs(TreeNode* root, int max_sofar) {
    if (root == nullptr) {
        return 0;
    }
    int total = 0;
    if (root->val >= max_sofar) {
        total++;
    }

    total += dfs(root->left, std::max(max_sofar, root->val));
    total += dfs(root->right, std::max(max_sofar, root->val));
    return total;

} 
    int goodNodes(TreeNode* root) {
        return dfs(root, std::numeric_limits<int>::min()); 
    }
};