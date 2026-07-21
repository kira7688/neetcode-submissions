class Solution {
public:
    struct Trie{
        char val;
        unordered_map<char, Trie*> nodes;
    };

    Trie* addChar(Trie* node, char c){
        if(node->nodes.count(c)){
            return node->nodes[c];
        }

        Trie* sub = new Trie;
        sub->val = c;
        node->nodes[c] = sub;

        return node->nodes[c];
    }

    void addWord(Trie* node, string word){
        for(char c: word){
            node = addChar(node, c);
        }
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
        return true;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int& m, int &n, int x, int y, int len, Trie *node){
        if(len==10){
            return;
        }

        node = addChar(node, board[x][y]);
        visited[x][y] = true;

        if(x>0 && !visited[x-1][y]){
            dfs(board, visited, m, n, x-1, y, len+1, node);
        }
        if(x<m-1 && !visited[x+1][y]){
            dfs(board, visited, m, n, x+1, y, len+1, node);
        }
        if(y>0 && !visited[x][y-1]){
            dfs(board, visited, m, n, x, y-1, len+1, node);
        }
        if(y<n-1 && !visited[x][y+1]){
            dfs(board, visited, m, n, x, y+1, len+1, node);
        }

        visited[x][y] = false;

        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        Trie root;
        root.val = '*';

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board, visited, m, n, i, j, 0, &root);
            }
        }

        vector<string> res;
        for(string word: words){
            if(findWord(&root, word)){
                res.push_back(word);
            }
        }

        return res;
    }
};