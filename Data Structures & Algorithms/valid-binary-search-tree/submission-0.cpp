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
    void inorder(TreeNode* node, int& mini, bool& valid, int& k){
        if(!node){
            return;
        }
        if(!valid){
            return;
        }
        inorder(node->left, mini, valid, k);
        if(!valid){
            return;
        }
        if(node->val <= mini){
            if(k!=1){
                valid = false;
                return;
            }
        }
        k++;
        mini = node->val;
        inorder(node->right, mini, valid, k);

        return;
    }
    bool isValidBST(TreeNode* root) {
        bool valid = true;
        int mini = INT_MIN;
        int k = 1;
        inorder(root, mini, valid, k);

        return valid;
    }
};