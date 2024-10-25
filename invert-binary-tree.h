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
    void helper(TreeNode* node)  // This will swap from top to down  // Conveniently inverting the tree
    {
        if (node == nullptr) return;

        // Swap the left and right children
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively invert the left and right subtrees
        helper(node->left);
        helper(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
