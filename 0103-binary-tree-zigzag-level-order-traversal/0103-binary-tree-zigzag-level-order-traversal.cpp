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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        if (root == nullptr) {
            return res; 
        }
        queue<TreeNode*> level; 
        level.push(root); 

        bool left_to_right = true; 

        while (!level.empty()) {
            int n = level.size();
            list<int> new_level; 
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front(); 

                if (left_to_right) {
                    new_level.emplace_back(node->val);
                }

                else {
                    new_level.emplace_front(node->val); 
                }

                if (node->left != nullptr) {
                    level.push(node->left);
                } 

                if (node->right != nullptr) {
                    level.push(node->right); 
                }
                
            level.pop();
            }
            
        res.emplace_back(new_level.begin(), new_level.end()); 
        left_to_right = !left_to_right; 
        }

        return res; 
}
};