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

int getInorderSuccessor(TreeNode* temp)
{
    TreeNode* root = temp->right;
    TreeNode* prev = root;
    
    while(root->left != nullptr)
    {
        prev = root;
        root = root->left;
    }
    
    int IC = root->val;

    if(root->right)
    {
        prev->left = root->right;
    }
    else
    {
        prev->left = nullptr;
    }

    delete root;

    return IC;

}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == nullptr)
        {
            return root;
        }

        TreeNode* temp = root;
        TreeNode* prev = nullptr;
        
        // Loop until you find the key or reach a nullptr
        while(temp != nullptr && temp->val != key)
        {
            if(key > temp->val)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }

        if(temp == root)  // The node to delete is the root of the tree
        {
            int IC = getInorderSuccessor(temp);
            temp->val = IC;
            return root;
        }

        if(temp->left && temp->right)  // Both children exist
        {
            int IC = getInorderSuccessor(temp);
            temp->val = IC;
        }
        else if(temp->right)  // Right child
        {
            prev->right = temp->right;
        }
        else  // Left child
        {
            prev->left = temp->left;
        }

        delete temp;
        return root;
    }
};