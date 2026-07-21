class WordDictionary {
private:
    char val;
    WordDictionary* nodes[26] = {NULL};
    bool isWord = false;
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        if(word.empty()){
            isWord = true;
            return;
        }
        char c = word[0];
        if(!nodes[c-97]){
            nodes[c-97] = new WordDictionary();
            nodes[c-97]->val = c;
        }
        nodes[c-97]->addWord(word.substr(1));
    }
    
    bool search(string word) {
        if(word.empty()){
            return isWord;
        }
        char c = word[0];
        if(c=='.'){
            bool check = false;
            for(int i=0;i<26;i++){
                if(!nodes[i]){
                    continue;
                }
                check = nodes[i]->search(word.substr(1));
                if(check){
                    return true;
                }
            }
        }
        else{
            if(!nodes[c-97]){
                return false;
            }

            return nodes[c-97]->search(word.substr(1));
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */