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
    TreeNode* first=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=new TreeNode(INT_MIN);
    TreeNode* mid=NULL;
    void solve(TreeNode* root){
        if(root==NULL) return ;
        solve(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }
            else last=root;
        }
        prev=root;
        solve(root->right);


    }
    void recoverTree(TreeNode* root){ 
        solve(root);
        if(first && last) swap(first->val,last->val);
        else swap(first->val,mid->val);
    }
};