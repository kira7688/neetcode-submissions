class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int inc_x = 0, inc_y = 1;

        int x_min = 1, x_max = matrix.size()-1, y_min = 0, y_max = matrix[0].size()-1;

        vector<int> res;

        int x = 0, y = 0;
        while(1){
            res.push_back(matrix[x][y]);
            
            if(inc_x){
                if(x+inc_x < x_min){
                    inc_x = 0;
                    inc_y = 1;
                    x_min += 1;
                    y += inc_y;
                    if(y>y_max){
                        break;
                    }
                }
                else if(x+inc_x > x_max){
                    inc_x = 0;
                    inc_y = -1;
                    x_max -= 1;
                    y += inc_y;
                    if(y<y_min){
                        break;
                    }
                }
                else{
                    x += inc_x;
                }
            }
            else{
                if(y+inc_y < y_min){
                    inc_x = -1;
                    inc_y = 0;
                    y_min += 1;
                    x += inc_x;
                    if(x<x_min){
                        break;
                    }
                }
                else if(y+inc_y > y_max){
                    inc_x = 1;
                    inc_y = 0;
                    y_max -= 1;
                    x += inc_x;
                    if(x>x_max){
                        break;
                    }
                }
                else{
                    y += inc_y;
                }
            }
        }

        return res;

    }
};