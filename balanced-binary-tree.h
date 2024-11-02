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
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return 1+max(maxDepth(root->right), maxDepth(root->left));
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == nullptr) return 1;

        if(abs(maxDepth(root->left) - maxDepth(root->right)) >= 2)
        {
            return 0;
        }
        return (isBalanced(root->right) && isBalanced(root->left));
    }
};