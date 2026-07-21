class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int& m, int& n){
        
        visited[i][j] = true;
        if(i>0 && grid[i-1][j]=='1' && !visited[i-1][j]){
            dfs(grid, visited, i-1, j, m, n);
        }
        if(i<m-1 && grid[i+1][j]=='1' && !visited[i+1][j]){
            dfs(grid, visited, i+1, j, m, n);
        }
        if(j>0 && grid[i][j-1]=='1' && !visited[i][j-1]){
            dfs(grid, visited, i, j-1, m, n);
        }
        if(j<n-1 && grid[i][j+1]=='1' && !visited[i][j+1]){
            dfs(grid, visited, i, j+1, m, n);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid, visited, i, j, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};