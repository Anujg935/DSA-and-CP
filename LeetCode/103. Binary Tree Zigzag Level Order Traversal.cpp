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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        queue<TreeNode* > q;
        q.push(root);
        bool odd = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> curr(n,0);
            if(odd){
                for(int i=0;i<n;i++){
                    curr[i] = q.front()->val;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                    odd = false;
                }
            }
            else{
                
                for(int i=0;i<n;i++){
                    curr[n-i-1] = q.front()->val;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                    odd = true;
                }
                
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};