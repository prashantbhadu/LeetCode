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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int mini=q.empty();
            int first,last;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                long long levels=q.front().second-mini;
                q.pop();
                if(i==0)first=levels;
                if(i==sz-1)last=levels;
                if(node->left!=NULL){
                    q.push({node->left,levels*2+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,levels*2+2}); 
                }
            }
            ans=max(ans,(last-first) +1);
            
        }
        
        return ans;

    }
};