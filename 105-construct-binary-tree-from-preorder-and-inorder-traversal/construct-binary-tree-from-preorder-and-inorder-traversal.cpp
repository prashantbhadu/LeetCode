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
    TreeNode* build(vector<int>&preorder,vector<int>&inorder, int prestart,int prend,int instart,int inend, map<int,int>&mp){
        if(prestart>prend || instart>inend) return NULL;
        TreeNode* node=new TreeNode(preorder[prestart]);
        int inroot=mp[node->val];
        int left=inroot-instart;
        node->left=build(preorder,inorder,prestart+1,prestart+left,instart,inroot-1,mp);
        node->right=build(preorder,inorder,prestart+left+1,prend,inroot+1,inend,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans= build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
        return ans;
    }
};