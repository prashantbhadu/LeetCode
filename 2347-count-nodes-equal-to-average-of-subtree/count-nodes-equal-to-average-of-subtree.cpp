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
    int count=0;
    pair<int,int> find(TreeNode* root ){
        if(root== NULL) return {0,0};
        if(root->left == NULL && root->right == NULL){
            count++; 
            return { root->val, 1};
        }
        pair<int,int> lef = find(root->left);
        pair<int,int> righ = find(root->right);
        
        int nodecount = lef.second + righ.second + 1;
        int sum = lef.first + righ.first + root->val;
        if((int)(sum/nodecount) == root->val)count++;
        return {sum, nodecount};
    }
    int averageOfSubtree(TreeNode* root) {
        find(root);
        return count;
    }
};