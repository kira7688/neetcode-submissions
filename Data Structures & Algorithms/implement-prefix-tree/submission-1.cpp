class PrefixTree {
private:
    vector<PrefixTree*> chars;
    bool isEnd;
public:
    PrefixTree() {
        chars.assign(26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        PrefixTree* root = this;
        for(char ch: word){
            if(!root->chars[ch-'a']){
                root->chars[ch-'a'] = new PrefixTree;
            }
            root = root->chars[ch-'a'];
        }
        root->isEnd = true;
        return;
    }
    
    bool search(string word) {
        PrefixTree* root = this;
        for(char ch: word){
            if(!root->chars[ch-'a']){
                return false;
            }
            root = root->chars[ch-'a'];
        }
        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* root = this;
        for(char ch: prefix){
            if(!root->chars[ch-'a']){
                return false;
            }
            root = root->chars[ch-'a'];
        }
        return true;
    }
};
