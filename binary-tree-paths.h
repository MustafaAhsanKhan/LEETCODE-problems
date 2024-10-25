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

    void helper(TreeNode* a, string curr)
    {
        if (a == nullptr)
        {
            return;
        }

        curr += to_string(a->val);

        if(a->right == nullptr && a->left == nullptr)
        {
            result.push_back(curr);  // Only add the string when reached a leaf node
        }
        else
        {
            curr += "->";
            helper(a->right, curr);
            helper(a->left, curr);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(root == nullptr) { return result; }
        
        helper(root, "");

        return result;
    }
};