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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both trees are empty
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one tree is empty but the other is not, return false
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If the values of the current nodes are different, return false
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
