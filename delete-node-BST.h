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

// int getInorderSuccessor(TreeNode* temp)
// {
//     // TreeNode* root = temp->right;
//     // TreeNode* prev = root;
    
//     // while(root->left != nullptr)
//     // {
//     //     prev = root;
//     //     root = root->left;
//     // }
    
//     // int IC = root->val;

//     // if(root->right)
//     // {
//     //     prev->left = root->right;
//     // }
//     // else
//     // {
//     //     prev->left = nullptr;
//     // }

//     // delete root;

//     // return IC;
//     if(temp->right != NULL){
//      TreeNode* temp1 = temp-> right;

//     }else{
//         return -1;
//     }

//     while(temp1->left){
//         temp1 = temp1->left;
//     }
//     return temp1->data;

// }

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key)
//     {
//         if(root == nullptr)
//         {
//             return root;
//         }

//         TreeNode* temp = root;
//         TreeNode* prev = nullptr;
        
//         // Loop until you find the key or reach a nullptr
//         while(temp != nullptr && temp->val != key)
//         {
//             if(key > temp->val)
//             {
//                 prev = temp;
//                 temp = temp->right;
//             }
//             else
//             {
//                 prev = temp;
//                 temp = temp->left;
//             }
//         }

//         if(temp == root)  // The node to delete is the root of the tree
//         {
//             int IC = getInorderSuccessor(temp);
//             temp->val = IC;
//             return root;
//         }

//         if(temp->left && temp->right)  // Both children exist
//         {
//             int IC = getInorderSuccessor(temp);
//             temp->val = IC;
//         }
//         else if(temp->right)  // Right child
//         {
//             prev->right = temp->right;
//         }
//         else  // Left child
//         {
//             prev->left = temp->left;
//         }

//         delete temp;
//         return root;
//     }
// };


int getInorderSuccessor(TreeNode* temp)
{
    // TreeNode* root = temp->right;
    // TreeNode* prev = root;
    
    // while(root->left != nullptr)
    // {
    //     prev = root;
    //     root = root->left;
    // }
    
    // int IC = root->val;

    // if(root->right)
    // {
    //     prev->left = root->right;
    // }
    // else
    // {
    //     prev->left = nullptr;
    // }

    // delete root;

    // return IC;
    if(temp->right != NULL){
     TreeNode* temp1 = temp-> right;

    }else{
        return -1;
    }

    while(temp1->left){
        temp1 = temp1->left;
    }
    return temp1->data;

}

class Solution {
public:
TreeNode* search(int key, TreeNode* root){
    TreeNode* curr=root;
    while(current!=NULL){
        if(current->val==key){
            return current;
        }
        if(current->val<key){
            current=current->left;
        }
        else{
            current=current->right;
        }

    }
    return current;
}
int getMin(TreeNode* del){
    if(del->right==NULL){
        return NULL;
    }
    else{
        del=del->right;
    }
    while(del->left!=NULL){
        del=del->left;
    }
    delete del;
    return del->val;
}
TreeNode* findParent(treeNode* del, treeNode* root){
    TreeNode* parent=root;
    TreeNode* current;
    while(current!=NULL){
        
    }

}
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* del=search(key,root);
        if(del==NULL){
            return root;
        }
        int x=getMin(del);

        TreeNode* temp=new node(x);

        temp->right=del->right;
        temp->left=del->left;
        return root;

    }
};

