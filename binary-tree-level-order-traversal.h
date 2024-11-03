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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty())
        {
            vector<int> curr;
            int levelSize = q1.size();

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* temp = q1.front();
                q1.pop();
                curr.push_back(temp->val);
                
                if (temp->left) q1.push(temp->left);
                if (temp->right) q1.push(temp->right);
            }
            
            res.push_back(curr);
        }
        
        return res;
    }
};