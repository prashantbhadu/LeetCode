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
    int maxLevelSum(TreeNode* root) {
        vector<int>sum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int add=0;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    
                }
                if(node->right){
                    q.push(node->right);
                }
                add+=node->val;

            }
            sum.push_back(add);
        }
        int temp=INT_MIN;
        int ans=0;
        for(int i=0;i<sum.size();i++){
            if(temp<sum[i]){
                temp=sum[i];
                ans=i;

            }
        }
        return ans+1;
        
    }
};