/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    vector<vector<int>> preorder(TreeNode* node, int i){
        if(!node){
            return vector<vector<int>>();
        }

        vector<vector<int>> ans, left, right;

        vector<int> self;
        self.push_back(node->val);
        
        left = preorder(node->left, i+1);
        if(!left.empty()){
            self.push_back(i+1);
        }
        else{
            self.push_back(-1);
        }
        right = preorder(node->right, i+1+left.size());
        if(!right.empty()){
            self.push_back(i+1+left.size());
        }
        else{
            self.push_back(-1);
        }

        ans.push_back(self);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        vector<vector<int>> order;
        order= preorder(root, 0);

        string s = "";

        int m = order.size();
        for(int i=0;i<m;i++){
            s += to_string(i)  + ':';
            s += to_string(order[i][0]) + ';';
            s += to_string(order[i][1]) + '.';
            s += to_string(order[i][2]) + ',';
        }

        //cout << s << endl;

        return s;
    }

    TreeNode* buildTree(unordered_map<int,vector<int>>& preorder, int ind){
        if(!preorder.count(ind)){
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[ind][0]);
        node->left = buildTree(preorder, preorder[ind][1]);
        node->right = buildTree(preorder, preorder[ind][2]);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int m = data.size();
        if(m==1){
            return NULL;
        }

        string temp = "";
        int ind = 0;

        unordered_map<int,vector<int>> preorder;
        for(int i=0;i<m;i++){
            if(data[i]==':'){
                ind = stoi(temp);
                temp = "";
            }
            else if(data[i]==';' || data[i]=='.' || data[i]==','){
                preorder[ind].push_back(stoi(temp));
                temp = "";
            }
            else{
                temp += data[i];
            }
        }

        return buildTree(preorder, 0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));