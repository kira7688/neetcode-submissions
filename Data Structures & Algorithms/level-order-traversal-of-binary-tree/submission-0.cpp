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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return vector<vector<int>>();
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<vector<int>> ans;
        vector<int> level;
        while(!q.empty()){
            root = q.front();
            q.pop();

            if(!root){
                ans.push_back(level);
                if(!q.empty()){
                    q.push(NULL);
                }
                level.clear();
                continue;
            }
            level.push_back(root->val);

            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }

        return ans;
    }
};