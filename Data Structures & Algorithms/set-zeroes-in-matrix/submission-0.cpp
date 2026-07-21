class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto row: rows){
            matrix[row] = vector<int>(n, 0);
        }
        for(auto col: cols){
            for(int i=0;i<m;i++){
                matrix[i][col] = 0;
            }
        }
    }
};