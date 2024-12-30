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

    TreeNode* helper1(TreeNode* root, int val)
    {
        if(!root)
        {
            return root;
        }

        if(root->val == val)
        {
            return root;
        }

        helper1(root->left, val);
        helper1(root->right, val);
        return root;
    }

    bool helper(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot)
        {
            return true;
        }

        if(root->val != subRoot->val)
        {
            return false;
        }

        return helper(root->right, subRoot->right) && helper(root->left, subRoot->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        root = helper1(root, subRoot->val);
        if(!root)
        {
            return 0;
        }

        return helper(root, subRoot);
    }
};