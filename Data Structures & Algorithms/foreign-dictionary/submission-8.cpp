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

    void dfs(unordered_map<char,string>& rules, char c, unordered_map<char,int>& rank, int level, unordered_set<int> path, bool& isValid, int& maxRank){
        path.insert(c);
        rank[c] = max(rank[c], level);
        maxRank = max(maxRank, rank[c]);

        for(char ch: rules[c]){
            if(ch=='*'){
                continue;
            }
            if(path.count(ch)){
                isValid = false;
                return;
            }
            else{
                dfs(rules, ch, rank, level+1, path, isValid, maxRank);
            }
        }

        return;
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
        
        unordered_map<char,string> rules;

        for(Trie* node: root->nodes){
            q.push(node);
        }
        
        q.push(NULL);

        Trie* node;
        char prev = '0';
        while(!q.empty()){
            node = q.front();
            q.pop();

            if(!node){
                if(prev!='0' && !rules.count(prev)){
                    rules[prev] = "*";
                }
                prev = '0';
                //cout << endl;
                //cout << "level" << endl;
                continue;
            }

            //cout << node->val << " ";

            for(Trie* n: node->nodes){
                q.push(n);
            }
            q.push(NULL);

            if(prev!='0'){
                if(prev==node->val){
                    return "";
                }
                if(!rules.count(prev)){
                    rules[prev] = node->val;
                }
                else{
                    bool check = false;
                    for(char c: rules[prev]){
                        if(c==node->val){
                            check = true;
                        }
                    }
                    if(rules[prev][0]=='*'){
                        rules[prev] = node->val;
                    }
                    else if(!check){
                        rules[prev] += node->val;
                    }
                }
            }
            prev = node->val;
        }
        //cout << endl;

        unordered_map<char,int> rank;
        for(pair<char,string> p: rules){
            //cout << "c=" << p.first << " , s=" << p.second << endl;
            if(!rank.count(p.first)){
                rank[p.first] = 0;
            }
            for(char ch: p.second){
                if(ch=='*'){
                    continue;
                }
                if(!rank.count(ch)){
                    rank[ch] = 1;
                }
            }
        }

        unordered_map<char,int> rankcopy(rank);
        bool isValid = true;
        int maxRank = 0;
        for(pair<char,int> p: rankcopy){
            if(p.second==0){
                dfs(rules, p.first, rank, 0, {}, isValid, maxRank);
                if(!isValid){
                    return "";
                }
            }
        }

        vector<string> ranked(maxRank+1, "");

        for(pair<char,int> p: rank){
            ranked[p.second] += p.first;
        }

        for(string s: ranked){
            ans += s; 
        }

        return ans;
    }
};
