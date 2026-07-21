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
    int search(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& res, int& found){
        if(found==2){
            return 0;
        }
        if(!node){
            return 0;
        }
        int self = 0;
        if(node==p || node==q){
            found++;
            self = 1;
        }
        if(found==2){
            return self;
        }
        int left = search(node->left, p, q, res, found);
        if(self && left){
            res = node;
        }
        if(found==2){
            return self+left;
        }
        int right = search(node->right, p, q, res, found);
        if(self && right){
            res = node;
        }
        else if(left && right){
            res = node;
        }
        if(res){
            return 0;
        }

        return self+left+right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        int found;
        search(root, p, q, res, found);

        return res;
    }
};