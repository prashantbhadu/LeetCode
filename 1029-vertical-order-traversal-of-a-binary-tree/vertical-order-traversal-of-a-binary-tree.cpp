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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                int level=q.front().second;
                q.pop();
                mp[level].push_back({count,node->val});
                if(node->left) q.push({node->left,level-1});
                if(node->right)q.push({node->right,level+1});
            }
            count++;
        }
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            vector<int>rslt;
            for(auto pp:it.second){
                rslt.push_back(pp.second);
            }
            ans.push_back(rslt);
        }
        return ans;
    }
};