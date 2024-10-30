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

#include <iostream>
using namespace std;


class Solution {
public:

    TreeNode* getSuccessor(TreeNode* curr)
    {
        curr = curr->right;
        while (curr != NULL && curr->left != NULL)
            curr = curr->left;
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        // Base case
        if (root == NULL)
            return root;

        // If key to be searched is in a subtree
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else  // Node found with the given key
        {
            if (root->left == NULL)  // 0 children or only right child
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // When root has only left child
            if (root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // When both children are present
            TreeNode* succ = getSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};