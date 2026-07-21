class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int m = nums.size();

        int prod = 1;
        int count_zero = 0;
        int zero_ind = -1;
        for(int i=0;i<m;i++){
            if(nums[i])
                prod *= nums[i];
            else{
                count_zero++;
                zero_ind = i;
            }
        }

        if(count_zero>1){
            return vector<int>(m, 0);
        }
        else if(count_zero==1){
            vector<int> prods(m, 0);
            prods[zero_ind] = prod;
            return prods;
        }

        vector<int> prods(m, prod);
        for(int i=0;i<m;i++){
            prods[i] = prods[i]/nums[i];
        }

        return prods;
    }
};