class PrefixTree {
private:
    char val;
    PrefixTree* nodes[26] = {NULL};
    bool isWord = false;

public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        if(word.empty()){
            isWord = true;
            return;
        }

        char c = word[0];
        if(!nodes[c-97]){
            nodes[c-97] = new PrefixTree();
            nodes[c-97]->val = c;
        }
        nodes[c-97]->insert(word.substr(1));

        return;
    }
    
    bool search(string word) {
        if(word.empty()){
            return isWord;
        }

        char c = word[0];
        if(!nodes[c-97]){
            return false;
        }

        return nodes[c-97]->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
        if(prefix.empty()){
            return true;
        }

        char c = prefix[0];
        if(!nodes[c-97]){
            return false;
        }

        return nodes[c-97]->startsWith(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */