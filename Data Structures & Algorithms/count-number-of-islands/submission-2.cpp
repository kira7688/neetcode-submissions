class Solution {
public:
    void explore(int i, int j, int m, int n, vector<vector<char>>& grid){
        grid[i][j] = '0';
        if(i<m-1 && grid[i+1][j]=='1'){
            explore(i+1, j, m, n, grid);
        }
        if(j<n-1 && grid[i][j+1]=='1'){
            explore(i, j+1, m, n, grid);
        }
        if(i>0 && grid[i-1][j]=='1'){
            explore(i-1, j, m, n, grid);
        }
        if(j>0 && grid[i][j-1]=='1'){
            explore(i, j-1, m, n, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    explore(i, j, m, n, grid);
                }
            }
        }

        return islands;
    }
};
