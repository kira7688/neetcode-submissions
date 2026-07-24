/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        unordered_map<int, Node*> seen;

        queue<Node*> q;
        q.push(node);

        Node *copy;
        copy = new Node(node->val);
        seen[node->val] = copy;

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(auto neighbor: node->neighbors){
                if(!seen.count(neighbor->val)){
                    seen[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                seen[node->val]->neighbors.push_back(seen[neighbor->val]);
            }
        }
        
        return copy;
    }
};
