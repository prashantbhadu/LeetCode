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
    void helper(TreeNode* root, int k, vector<int>&ans){
        if(root==NULL) return;
        if(root->left!=NULL) helper(root->left,k,ans);
        ans.push_back(root->val);
        if(root->right!=NULL) helper(root->right,k,ans); 
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        helper(root,k,ans);
        if(k>ans.size()) return 0;
        return ans[k-1];

    }
};