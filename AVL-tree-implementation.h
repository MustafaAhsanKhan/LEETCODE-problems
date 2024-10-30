#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): data(x), height(0), left(nullptr), right(nullptr) {}
}

class AVL_Tree
{
private:
    TreeNode* root;

public:
    AVL_Tree()
    {

    }

    int height()
    {
        return abs(max(root->left, root->right) + 1);
    }

    void insert(int x)
    {
        if(root == nullptr)
        {
            root = new TreeNode(x);
            return;
        }
        else if(x < root->data)
        {
            root->left = insert(root->left, x);
            if(height() == 2)
            {

            }
        }
        else if(x >= root->data)
        {
            root->right = insert(root->right, x);
            if(height() == 2)
            {

            }
        }
    }
}