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
    bool func(TreeNode* lefty, TreeNode* righty){
        if(lefty==NULL && righty==NULL)return true;
        if(lefty!=NULL && righty==NULL)return false;
        if(lefty==NULL && righty!=NULL)return false;
        if(lefty->val!=righty->val)return false;
        return (func(lefty->left,righty->right)&&func(lefty->right,righty->left));
    }
    bool isSymmetric(TreeNode* root) {
        return func(root->left,root->right);
    }
};