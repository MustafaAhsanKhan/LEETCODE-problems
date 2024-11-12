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

    vector<int> res;

    void inorderTraversal(TreeNode* node, vector<int>& res)
    {
        if(node == nullptr) return;

        inorderTraversal(node->left, res);
        res.push_back(node->val);
        inorderTraversal(node->right, res);
    }

    TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end)
    {
        // Base case
        if (start > end) return nullptr;
        
        // Find the middle element and make it root
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        
        // Recursively construct the left and right subtrees
        root->left = sortedArrayToBST(arr, start, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
        
        return root;
    }

    // Helper function to start the conversion from the sorted array
    TreeNode* sortedArrayToBST(vector<int>& arr)
    {
        return sortedArrayToBST(arr, 0, arr.size() - 1);
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        inorderTraversal(root, res);

        return sortedArrayToBST(res);
    }
};