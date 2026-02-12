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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int instart, int inend,int poststart,int postend,map<int,int>&mpp){
        if(instart>inend || poststart>postend) return NULL;
        TreeNode* node=new TreeNode(postorder[postend]);
        int inroot=mpp[node->val];
        int left=inroot-instart;
        node->left=build(inorder,postorder,instart,inroot-1,poststart,poststart+left-1,mpp);
        node->right=build(inorder,postorder,inroot+1,inend,poststart+left,postend-1,mpp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* ans=build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mpp);
        return ans;
    }
};