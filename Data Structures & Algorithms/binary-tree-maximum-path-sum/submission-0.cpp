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
    int helper(TreeNode* node, int& maxSum){
        if(!node){
            return 0;
        }

        int left = helper(node->left, maxSum);
        int right = helper(node->right, maxSum);

        int sum = node->val + left + right;
        if(sum>maxSum){
            maxSum = sum;
        }

        return max(0, max(left,right) + node->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);

        return maxSum;
    }
};