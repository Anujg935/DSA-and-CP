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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> res;
        if(!root){
            return res;
        }
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode *front = q.front();
            res.push_back(front->val);
            
            int n = q.size();
            int i =0;
            while(i<n){
                TreeNode *front = q.front();
                q.pop();
                if(front->right)
                    q.push(front->right);
                if(front->left)
                    q.push(front->left);
            
                i++;
            }
            
        }
        
        return res;
    }
};