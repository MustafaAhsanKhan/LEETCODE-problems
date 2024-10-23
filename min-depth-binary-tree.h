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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;  // Base case: if the tree is empty, the depth is 0

        // If the node is a leaf (no children), return 1
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        // If one of the children is nullptr, we should only consider the other subtree
        if (root->left == nullptr)
            return 1 + minDepth(root->right);
        if (root->right == nullptr)
            return 1 + minDepth(root->left);

        // If both children are present, return the minimum depth of both subtrees
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
