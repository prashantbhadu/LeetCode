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
    int res=INT_MIN;
    int dinky_loves_sajal(TreeNode* root){
        if(root==NULL) return 0;
        int left= max(0,dinky_loves_sajal(root->left));
        int right=max(0,dinky_loves_sajal(root->right));
        res=max(res,left+right+root->val);
        return root->val+max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        dinky_loves_sajal(root);
        return res;
    }
};