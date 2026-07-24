class Solution {
public:
    void explore(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& exp){
        exp[i][j] = true;
        if(i<m-1 && grid[i+1][j]=='1' && !exp[i+1][j]){
            explore(i+1, j, m, n, grid, exp);
        }
        if(j<n-1 && grid[i][j+1]=='1' && !exp[i][j+1]){
            explore(i, j+1, m, n, grid, exp);
        }
        if(i>0 && grid[i-1][j]=='1' && !exp[i-1][j]){
            explore(i-1, j, m, n, grid, exp);
        }
        if(j>0 && grid[i][j-1]=='1' && !exp[i][j-1]){
            explore(i, j-1, m, n, grid, exp);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> exp(m, vector<bool>(n, false));

        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!exp[i][j] && grid[i][j]=='1'){
                    islands++;
                    explore(i, j, m, n, grid, exp);
                }
            }
        }

        return islands;
    }
};
