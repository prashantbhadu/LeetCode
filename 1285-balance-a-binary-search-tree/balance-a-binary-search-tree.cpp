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
    int res=0;
    void solve(TreeNode* root,vector<TreeNode*>&store){
       if(root==NULL)return;
       solve(root->left,store);
       store.push_back(root);
       solve(root->right,store);
    }
    TreeNode* balance(vector<TreeNode*>&ans, int start, int last){
        if(start>last) return NULL;
        int mid=(start+last)/2;
        TreeNode* left=balance(ans,start,mid-1);
        TreeNode* right=balance(ans,mid+1,last);
        ans[mid]->left=left;
        ans[mid]->right=right;
        return ans[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
       vector<TreeNode*>store;
       solve(root,store);
       return balance(store,0,store.size()-1);
        

        
    }
};