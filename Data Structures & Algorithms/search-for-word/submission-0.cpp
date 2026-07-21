class Solution {
public:
    void helper(vector<vector<char>>& board, int x, int y, int &m, int &n, vector<vector<bool>>& visited, vector<vector<int>>& dirs, string &word, int ind, int& l, bool& found){
        if(ind==l-1){
            found = true;
            return;
        }

        visited[x][y] = true;

        if(x>0){
            if(!visited[x-1][y] && board[x-1][y]==word[ind+1]){
                helper(board, x-1, y, m, n, visited, dirs, word, ind+1, l, found);
                if(found){
                    return;
                }
            }
        }
        if(x<m-1){
            if(!visited[x+1][y] && board[x+1][y]==word[ind+1]){
                helper(board, x+1, y, m, n, visited, dirs, word, ind+1, l, found);
                if(found){
                    return;
                }
            }
        }
        if(y>0){
            if(!visited[x][y-1] && board[x][y-1]==word[ind+1]){
                helper(board, x, y-1, m, n, visited, dirs, word, ind+1, l, found);
                if(found){
                    return;
                }
            }
        }
        if(y<n-1){
            if(!visited[x][y+1] && board[x][y+1]==word[ind+1]){
                helper(board, x, y+1, m, n, visited, dirs, word, ind+1, l, found);
                if(found){
                    return;
                }
            }
        }

        visited[x][y] = false;

        return;
    }

    bool exist(vector<vector<char>>& board, string word){
        vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int l = word.size();

        bool found = false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    helper(board, i, j, m, n, visited, dirs, word, 0, l, found);
                    if(found){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};