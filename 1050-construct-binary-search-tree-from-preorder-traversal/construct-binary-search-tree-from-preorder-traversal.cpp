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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        int i=1;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode* dummy=root;
        while(i<preorder.size()){
            if(root->val>preorder[i]){
                root->left=new TreeNode(preorder[i]);
                root=root->left;
                s.push(root);
            }
            else if(root->val<preorder[i]){
                while(!s.empty() && s.top()->val<preorder[i]){
                    root=s.top();
                    s.pop();
                }
                root->right=new TreeNode(preorder[i]);
                root=root->right;
                s.push(root);
            }
            i++;
        }
        return dummy;
    }
};