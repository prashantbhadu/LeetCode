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
    void solve(TreeNode*  root, unordered_map<int,int>&mpp){
        if(root==NULL) return ;
        mpp[root->val]=1;
        if(root->left) solve(root->left,mpp);
        if(root->right) solve(root->right,mpp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mpp;
        solve(root,mpp);
        for(auto val:mpp){
            int temp=val.first;
            int check=k-temp;
            if( check!=temp && mpp.find(check)!=mpp.end()) return true;
        }
        return false;
    }
};