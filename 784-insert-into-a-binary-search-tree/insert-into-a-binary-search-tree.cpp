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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        TreeNode* temp=root;
        TreeNode* prev=root;
        if(root==NULL) return node;
        while(temp!=NULL){
            prev=temp;
            if(temp->val > val){
                temp=temp->left;
            }
            else temp=temp->right;
        }
        if(prev->val>val) prev->left=node;
        else prev->right=node;
        return root;
    }
};