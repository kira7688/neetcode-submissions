class Solution {
public:
    void upSearch(int i, int j, int m, int n, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[i][j] = true;
        if(i+1<m && !ocean[i+1][j] && heights[i+1][j]>=heights[i][j]){
            upSearch(i+1, j, m, n, ocean, heights);
        }
        if(i-1>=0 && !ocean[i-1][j] && heights[i-1][j]>=heights[i][j]){
            upSearch(i-1, j, m, n, ocean, heights);
        }
        if(j+1<n && !ocean[i][j+1] && heights[i][j+1]>=heights[i][j]){
            upSearch(i, j+1, m, n, ocean, heights);
        }
        if(j-1>=0 && !ocean[i][j-1] && heights[i][j-1]>=heights[i][j]){
            upSearch(i, j-1, m, n, ocean, heights);
        }

        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            upSearch(i, n-1, m, n, atlantic, heights);
        }
        for(int j=0;j<n;j++){
            upSearch(m-1, j, m, n, atlantic, heights);
        }
        for(int i=0;i<m;i++){
            upSearch(i, 0, m, n, pacific, heights);
        }
        for(int j=0;j<n;j++){
            upSearch(0, j, m, n, pacific, heights);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
