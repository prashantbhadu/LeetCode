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
    int count(TreeNode* root){
        if(root==NULL) return 0;
        int left=count(root->left);
        int right = count(root->right);
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xnode=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val==x){
                xnode=curr;
                break;
            }
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        int right=count(xnode->right);
        int left=count(xnode->left);
        int parent=(n-left-right-1);
        if(max({parent,left,right})>n/2) return true;
        else return false;
    }
};