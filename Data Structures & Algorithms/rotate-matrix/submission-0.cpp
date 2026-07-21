class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int j_bound;
        
        int temp1, temp2, temp3, temp4;
        for(int i=0;i<(n/2);i++){
            for(int j=i;j<n-i-1;j++){
                temp1 = matrix[i][j];
                temp2 = matrix[j][n-1-i];
                temp3 = matrix[n-1-i][n-1-j];
                temp4 = matrix[n-1-j][i];

                matrix[i][j] = temp4;
                matrix[j][n-1-i] = temp1;
                matrix[n-1-i][n-1-j] = temp2;
                matrix[n-1-j][i] = temp3;
            }
        }

        return;
    }
};