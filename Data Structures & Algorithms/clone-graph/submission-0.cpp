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
    Node* helper(Node* node, unordered_map<int, Node*>& map){
        if(!node){
            return NULL;
        }
        if(map.count(node->val)){
            return map[node->val];
        }
        Node* newNode = new Node(node->val);
        map[node->val] = newNode;

        Node* temp;
        for(Node* neighbor: node->neighbors){
            newNode->neighbors.push_back(helper(neighbor, map));
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> map;
        return helper(node, map);
    }
};