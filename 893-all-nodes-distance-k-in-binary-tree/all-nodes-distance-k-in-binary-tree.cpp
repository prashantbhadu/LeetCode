/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentfunc(unordered_map<TreeNode*,TreeNode*>&mpp, TreeNode* root){
        if(root==NULL) return;

        if(root->left) mpp[root->left] = root;
        if(root->right) mpp[root->right] = root;

        parentfunc(mpp, root->left);
        parentfunc(mpp, root->right);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        parentfunc(mpp,root);

        queue<TreeNode*>q;
        q.push(target);

        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;

        int countlv=0;
        if(k == 0) return {target->val};

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(mpp.find(node) != mpp.end() && !visited[mpp[node]]){
                    q.push(mpp[node]);
                    visited[mpp[node]]=true;
                }
            }
            countlv++;
            if(countlv==k) break;
        }
        vector<int>ans;
        while(!q.empty()){
            int temp=q.front()->val;
            ans.push_back(temp);
            q.pop();
        }
        return ans;
        
    }
};