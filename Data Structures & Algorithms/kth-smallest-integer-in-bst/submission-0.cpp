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
    void inorder(TreeNode* node, int& k, int& kth){
        if(!node){
            return;
        }
        if(k==0){
            return;
        }
        inorder(node->left, k, kth);
        k--;
        if(k==0){
            kth = node->val;
            return;
        }
        inorder(node->right, k, kth);
        
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int kth;
        inorder(root, k, kth);

        return kth;
    }
};