class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int& m, int& n, vector<vector<bool>>& ocean){
        if(ocean[i][j]){
            return;
        }

        ocean[i][j] = true;

        if(i>0 && (heights[i][j] <= heights[i-1][j])){
            dfs(heights, i-1, j, m, n, ocean);
        }
        if(i<m-1 && (heights[i][j] <= heights[i+1][j])){
            dfs(heights, i+1, j, m, n, ocean);
        }
        if(j>0 && (heights[i][j] <= heights[i][j-1])){
            dfs(heights, i, j-1, m, n, ocean);
        }
        if(j<n-1 && (heights[i][j] <= heights[i][j+1])){
            dfs(heights, i, j+1, m, n, ocean);
        }
        
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            dfs(heights, i, 0, m, n, pacific);
            dfs(heights, i, n-1, m, n, atlantic);
        }

        for(int j=0;j<n;j++){
            dfs(heights, 0, j, m, n, pacific);
            dfs(heights, m-1, j, m, n, atlantic);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};