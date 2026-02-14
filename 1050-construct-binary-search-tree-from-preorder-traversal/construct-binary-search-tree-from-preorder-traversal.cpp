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
   TreeNode* solve(vector<int>&preorder,int start, int end){
    if(start>end) return NULL;
    TreeNode* root=new TreeNode(preorder[start]);
    int temp=end+1;
    for(int i=start;i<=end;i++){
        if(preorder[i]>root->val){
            temp=i;
            break;
        }
    }
      root->left=solve(preorder,start+1,temp-1);
      root->right=solve(preorder,temp,end);
      return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size()-1;
        return solve(preorder,0,n);
    }
};