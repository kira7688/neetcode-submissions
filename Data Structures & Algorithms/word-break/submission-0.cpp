class Solution {
public:

    struct Trie{
        char val;
        unordered_map<char,Trie*> nodes;
        bool isWord = false;
    };

    Trie* addChar(Trie* node, char c){
        if(!node->nodes.count(c)){
            Trie* sub = new Trie;
            sub->val = c;

            node->nodes[c] = sub;
        }

        return node->nodes[c];
    }

    void addWord(Trie* node, string word){
        for(char c: word){
            node = addChar(node, c);
        }
        node->isWord = true;
    }

    bool findWord(Trie* node, string word){
        for(char c: word){
            if(node->nodes.count(c)){
                node = node->nodes[c];
            }
            else{
                return false;
            }
        }
        return node->isWord;
    }

    bool findWordBreak(Trie* root, Trie* node, string& word, int start, int& len, vector<int>& dp){
        if(dp[start]!=-1){
            return dp[start];
        }

        for(int i=start;i<len;i++){
            if(node->isWord){
                if(findWordBreak(root, root, word, i, len, dp)){
                    dp[start] = 1;
                    return true;
                }
            }
            if(node->nodes.count(word[i])){
                node = node->nodes[word[i]];
            }
            else{
                dp[start] = 0;
                return false;
            }
        }

        dp[start] = node->isWord;

        return node->isWord;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie;
        for(string word: wordDict){
            addWord(root, word);
        }

        int len = s.size();
        vector<int> dp(len, -1);
        return findWordBreak(root, root, s, 0, len, dp);
    }
};