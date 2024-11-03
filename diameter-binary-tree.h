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
    int di(TreeNode* root, int &maxDia)
    {
        if(!root) return 0;
        int l = di(root->right, maxDia), r = di(root->left, maxDia);
        maxDia = max(maxDia, l + r);
        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int maxDia = 0;
        di(root, maxDia);
        return maxDia;
    }
};