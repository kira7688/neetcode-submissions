class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums.size();
        int prodNeg = 1 , prodPos = 1, maxProd = nums[0];
        int temp;
        for(int i=0;i<m;i++){
            if(nums[i]==0){
                prodNeg = 1;
                prodPos = 1;

                maxProd = max(maxProd, 0);
            }
            else if(nums[i] < 0){
                temp = prodPos;
                if(prodNeg < 0){
                    prodPos = prodNeg*nums[i];

                    maxProd = max(maxProd, prodPos);
                }
                else{
                    prodPos = 1;
                }

                prodNeg = temp*nums[i];
            }
            else{
                prodPos = prodPos*nums[i];
                prodNeg = prodNeg*nums[i];

                maxProd = max(maxProd, prodPos);
            }

            //cout << i << prodPos << prodNeg << maxProd << endl;
        }

        return maxProd;
    }
};