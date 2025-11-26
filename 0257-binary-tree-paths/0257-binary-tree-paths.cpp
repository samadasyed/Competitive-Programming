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

    void traverse(TreeNode* node, vector<string>& ans, string temp){ 
        
        temp += to_string(node->val); 
        if (node->left != nullptr){
            traverse(node->left, ans, temp + "->");
        }
        if (node->right != nullptr){
            traverse(node ->right, ans, temp + "->"); 
        }
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(temp); 
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans; 
        if (root != nullptr) {
            traverse(root, ans, "");
        }
        return ans; 
    }
};