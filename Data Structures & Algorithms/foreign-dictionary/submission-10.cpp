class Solution {
public:

    struct Trie{
        char val;
        vector<Trie*> nodes;
        unordered_map<char,int> ind;
        bool isWord = false;
    };

    Trie* addChar(Trie* node, char c){
        
        if(node->ind.count(c)){
            if(node->ind[c]!=node->nodes.size()-1){
                return NULL;
            }
            return node->nodes[node->ind[c]];
        }

        Trie* newNode = new Trie;
        newNode->val = c;

        node->ind[c] = node->nodes.size();
        node->nodes.push_back(newNode);

        return node->nodes[node->ind[c]];
    }

    bool addWord(Trie* node, string word){
        for(char c: word){
            node = addChar(node, c);
            if(!node){
                return false;
            }
        }
        if(node->nodes.size()){
            return false;
        }

        node->isWord = true;

        return true;
    }

    string foreignDictionary(vector<string>& words) {
        int m = words.size();
        
        string ans, temp;

        Trie* root = new Trie;
        for(string word: words){
            if(!addWord(root, word)){
                return "";
            }
        }

        queue<Trie*> q;
        
        Trie *node, *curr, *next, *prev;
        unordered_map<char,unordered_set<char>> adjList;
        unordered_map<char,int> rank;

        m = root->nodes.size();

        for(int i=0;i<m;i++){
            curr = root->nodes[i];
            rank[curr->val] = min(i,1);
            q.push(curr);

            if(i<m-1){
                next = root->nodes[i+1];
            
                adjList[curr->val].insert(next->val);
            }
            
        }

        while(!q.empty()){
            node = q.front();
            q.pop();

            m = node->nodes.size();
            if(m>0 && !rank.count(node->nodes[0]->val)){
                rank[node->nodes[0]->val] = 0;
            }
            for(int i=0;i<m;i++){
                
                curr = node->nodes[i];
                q.push(curr);

                if(i<m-1){
                    next = node->nodes[i+1];

                    if(rank.count(next->val)){
                        if(adjList.count(curr->val)){
                            if(adjList[curr->val].count(next->val)){
                                continue;
                            }
                        }
                        rank[next->val] += 1;
                    }
                    else{
                        rank[next->val] = 1;
                    }

                    adjList[curr->val].insert(next->val);
                }
            }
        }

        queue<char> topo;
        for(pair<char,int> p: rank){
            //cout << "p.first=" << p.first << " , p.second=" << p.second << endl;
            if(p.second==0){
                topo.push(p.first);
            }
        }

        char ch;
        while(!topo.empty()){
            ch = topo.front();
            topo.pop();

            ans += ch;

            for(char c: adjList[ch]){
                rank[c]--;
                if(rank[c]==0){
                    topo.push(c);
                }
            }
        }

        if(ans.size()!=rank.size()){
            return "";
        }

        return ans;
    }
};
