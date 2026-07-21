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
    TreeNode* helper(vector<int>& preorder, int& p, vector<int>& inorder, int is, int ie){
        if(is>ie){
            return NULL;
        }
        int isplit = -1;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==preorder[p]){
                isplit = i;
                break;
            }
        }

        TreeNode* node = new TreeNode;
        node->val = preorder[p];
        p++;
        node->left = helper(preorder, p, inorder, is, isplit-1);
        node->right = helper(preorder, p, inorder, isplit+1, ie);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int p = 0;
        
        return helper(preorder, p, inorder, 0, m-1);
    }
};