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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode* temp = root;
        while(temp != nullptr)
        {
            if(val > temp->val && temp->right == nullptr)
            {
                temp->right = new TreeNode(val);
                return root;
            }
            else if (val < temp->val && temp->left == nullptr)
            {
                temp->left = new TreeNode(val);
                return root;
            }
            else if(val > temp->val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        return root;
    }
};