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
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> helper(TreeNode* a, Treenode* b)
    {
        if (a == nullptr && b == nullptr)  // Reached leaf node
        {
            return result;
        }

        result.push_back(current_string);

        return helper(a->)
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        return helper(root->left, root->right);
    }
};