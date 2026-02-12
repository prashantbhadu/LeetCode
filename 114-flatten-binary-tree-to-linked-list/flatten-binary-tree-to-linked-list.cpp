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
    void store(TreeNode* root, queue<TreeNode*>&q){
        if(root==NULL) return ;
        q.push(root);
        store(root->left,q);
        store(root->right,q);
    }
    void flatten(TreeNode* root) {
        queue<TreeNode*>q;
        store(root,q);
        if(!q.empty()) q.pop();
        while(!q.empty()){
            root->left=NULL;
            root->right=q.front();
            q.pop();
            root=root->right;
        }
    }
};